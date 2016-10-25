if [[ ! -d "bugged" || ! -d "fixed" ]]; then
    echo "error: Demo repositories not found. please run setup.sh before this script."
    exit 1
fi

echo "=== BUGGED VERSION ==="
cd bugged/src
frama-c util.c -no-frama-c-stdlib -cpp-command "gcc -C -E -lpcre -llzma -I../../../../libraries/libc/include -D__FC_MACHDEP_X86_64" -wp -wp-fct binary_search -wp-rte -wp-timeout 60 "$@"
cd ../..
echo "=== FIXED VERSION ==="
cd fixed/src
frama-c util.c -no-frama-c-stdlib -cpp-command "gcc -C -E -lpcre -llzma -I../../../../libraries/libc/include -D__FC_MACHDEP_X86_64" -wp -wp-fct binary_search -wp-rte -wp-timeout 60 "$@"
cd ../..
echo "=== END ==="