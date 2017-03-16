# Bug in fetchsms


## Bug behavior

Unknown, there is no proof of concept, or example of an exploit.
## Source

http://www.kamailio.org/pub/openser/1.1.0/src/openser-1.1.0-tls_src.tar.gz
## Description of bug

&ldquo;A buffer, pdu[], is passed to fetchsms(). fetchsms() writes into pdu[] from another buffer, answer[], which it gets from the modem. fetchsms() does some heavyweight string parsing of answer[], and copies part of answer[] into pdu[]. Unfortunately, pdu[] is too small to hold this substring of answer[].&rdquo;

A response string is written into _answer_, which has a size limit of 512. The function which writes the response guarantees a valid string with a null terminator will be written, and truncates the response to fit. A substring from the response is found, and written into the function argument _pdu_. Because it is a substring of a bounded size string, we can assert if the write into _pdu_ is legal, if the size of _pdu_ is known. Until this point, _pdu_ is unmodified, so if an inadequately sized array is provided, the bug could manifest.
## Annotations

The libc header files from frama-c for string.h were used. Additionally, the provided contract for _sprintf_ was added.

The function _put_command_ in file _modules/sms/libsms_modem.c_ writes a command to the modem _mdm_, and copies as much of the response as can fit into _answer_. The value in _answer_ is always null terminated.

```
/*@
    requires \valid(answer+(0..max-1));
    assigns *(answer+(0..(max-1)));
    ensures valid_string(answer);
*/
 int put_command( struct modem *mdm, char* cmd, int cmd_len, char* answer,
                     int max, int timeout,char* exp_end)</verbatim>
```

The function _fetchsms_ in file<em> modules/sms/libsms_getsms.c</em> is where the bug occurs. The final two requires statements prevent the bug from occurring by constraining the size of _pdu_.
```
/*@
    requires \valid(mdm);
    requires \valid(pdu);
    requires \separated(mdm, pdu);

    requires \valid(pdu+(0..511));
    requires \separated(mdm, pdu+(0..511));
 */
 int fetchsms(struct modem *mdm, int sim, char* pdu)
 ```

Three simple loops in _fetchsms_ were annotated with assigns statements.
```
/*@ loop assigns end; */
```

Several assertions were added into the function _fetchsms_ to show the sizes of substrings are bounded, and that _pdu_ remained valid.

The lemma was added to assist the prover. The lemma verifies, indicating it is a tautology.
```
/*@
    lemma ValidAtLeastToZero:
        \forall char *s; valid_string(s) ==>
        ( \exists integer i;
             *(s+i) == 0
             && \valid(s+(0..i))
        );
*/
```
## Results

No fix was found to resolve this potential bug. However, there is an implicit pre-condition on _fetchsms_ which prevents the scenario.

The call to _strcpy_ on line 192 will fail the _room_string_ precondition if the precondition _requires \valid(pdu+(0..511))_ on _fetchsms_ is not present.

Additionally, it was found that there is potential for a run time error if a malformed response is received. On line 171, _position_ is set to the location of &ldquo;+CMGR:&rdquo;, which guarantees valid memory from _position_ to _position+6_, for each letter and the null terminator. Later, on line 178, _beginning_ is set to _position+7_, which is may not be a valid address. Then on line 184, _end_ is set to _beginning_, and dereferenced.

In actuality, an error here is not observed because a well formed response in this case follows &ldquo;+CMGR:&rdquo; with a space, then additional information (http://www.developershome.com/sms/cmgrCommand.asp). The potential error could be avoided by changing the search string to &ldquo;+CMGR: &ldquo;, with a space.

For this experiment, an annotation was added after the initial call on line 171 to assume a well formed response. The assertion _(position == 0) || (6&lt;= strlen(position) &lt; 512)_ validates, and the stronger assertion _(position == 0) || (7&lt;= strlen(position) &lt; 512)_ does not validate, as expected.

## Modifications & Mitigations

String literals were refactored as needed to instead use a temporary array, because <em>\valid </em>was incorrectly failing.

There was an issue with including the libc headers provided by frama-c, causing an error in gcc.

The option -pp-annot is used to allow the use of macros in annotations. However, this causes gcc warnings.

Some properties which were valid were timing out. If given enough time, it is possible the goals would be validated. Instead, because the property was known at one point in the program, assertions were added at points between the known location, and the location where the property was utilized, to assist in showing the property held. These extra annotations allowed validation in reasonable time.

Validation on string properties are extremely slow. The option -wp-split was sufficient for most, goals, but some required an extended timeout. A full validation took over an hour.

## References

http://blog.frama-c.com/public/scam09.pdf

http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2006-6876

https://github.com/REMath/implementations/tree/master/tanalysis/tanalysis/verisec%20v1.0/OpenSER/CVE-2006-6876
