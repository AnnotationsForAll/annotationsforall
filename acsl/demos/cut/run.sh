if [[ ! -d "bugged" || ! -d "fixed" ]]; then
    echo "error: Demo repositories not found. please run setup.sh before this script."
    exit 1
fi

echo "=== BUGGED VERSION ==="

cd bugged &&

frama-c -cpp-command "gcc -std=gnu99 -Isrc -Ilib -c -C -E -I../../../libraries/libc/include -D__FC_MACHDEP_X86_32 -DNDEBUG -nostdlib -DHAVE_DECL_MALLOC -DHAVE_DECL_MEMCHR -DHAVE_DECL_REALLOC" -wp -wp-timeout 30 -wp-prover why3:alt-ergo -kernel-msg-key pp -no-frama-c-stdlib -wp-model Typed+cast -wp-fct set_fields,is_printable_field,mark_printable_field,mark_range_start src/cut.c "$@"

cd ..

echo "=== FIXED VERSION ==="
cd fixed &&

frama-c -cpp-command "gcc -std=gnu99 -Isrc -Ilib -c -C -E -I../../../libraries/libc/include -D__FC_MACHDEP_X86_32 -DNDEBUG -nostdlib -DHAVE_DECL_MALLOC -DHAVE_DECL_MEMCHR -DHAVE_DECL_REALLOC" -wp -wp-timeout 30 -wp-prover why3:alt-ergo -kernel-msg-key pp -no-frama-c-stdlib -wp-model Typed+cast -wp-fct set_fields,is_printable_field,mark_printable_field,mark_range_start src/cut.c "$@"

cd ..
echo "=== END ==="