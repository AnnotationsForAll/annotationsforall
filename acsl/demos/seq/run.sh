if [[ ! -d "bugged" || ! -d "fixed" ]]; then
    echo "error: Demo repositories not found. please run setup.sh before this script."
    exit 1
fi

echo "=== BUGGED VERSION ==="

cd bugged/coreutils-6.10 &&

frama-c -cpp-command "gcc -std=gnu99 -I../../../../libraries/libc/include -D__FC_MACHDEP_X86_64 -Isrc -Ilib -c -C -E" -no-frama-c-stdlib -wp -wp-timeout 60 -wp-fct long_double_format src/seq.c -wp-prover why3:alt-ergo -wp-rte

cd ../..

echo "=== FIXED VERSION ==="
cd fixed/coreutils-6.10 &&

frama-c -cpp-command "gcc -std=gnu99 -I../../../../libraries/libc/include -D__FC_MACHDEP_X86_64 -Isrc -Ilib -c -C -E" -no-frama-c-stdlib -wp -wp-timeout 60 -wp-fct long_double_format src/seq.c -wp-prover why3:alt-ergo -wp-rte

cd ../..
echo "=== END ==="