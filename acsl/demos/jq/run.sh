if [[ ! -d "bugged" || ! -d "fixed" ]]; then
    echo "error: Demo repositories not found. please run setup.sh before this script."
    exit 1
fi

echo "=== BUGGED VERSION ==="
cd bugged
frama-c jv_aux.c -no-frama-c-stdlib -cpp-command "gcc -C -E -I. -I../../../libraries/libc/include -D__FC_MACHDEP_X86_64" -wp -wp-timeout 180 -wp-fct "parse_slice,jv_get,test_parse_slice,test_jv_get" "$@"
cd ..
echo "=== FIXED VERSION ==="
cd fixed/src
frama-c jv_aux.c -no-frama-c-stdlib -cpp-command "gcc -C -E -I. -I../../../../libraries/libc/include -D__FC_MACHDEP_X86_64" -wp -wp-timeout 180 -wp-fct "parse_slice,jv_get,test_parse_slice,test_jv_get" "$@"
cd ../..
echo "=== END ==="