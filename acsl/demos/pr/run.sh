if [[ ! -d "bugged" || ! -d "fixed" ]]; then
    echo "error: Demo repositories not found. please run setup.sh before this script."
    exit 1
fi

echo "=== BUGGED VERSION ==="

cd bugged/coreutils-6.10 &&

frama-c -cpp-command "gcc -std=gnu99 -Isrc -Ilib -c -C -E -I../../../../libraries/libc/include -D__FC_MACHDEP_X86_32 -nostdlib"  -wp -wp-timeout 30 -wp-prover why3:alt-ergo -no-tty -kernel-msg-key pp -no-frama-c-stdlib -wp-fct char_to_clump,read_line src/pr.c "$@" -then -report

cd ../..

echo "=== FIXED VERSION ==="
cd fixed/coreutils-6.11 &&

frama-c -cpp-command "gcc -std=gnu99 -Isrc -Ilib -c -C -E -I../../../../libraries/libc/include -D__FC_MACHDEP_X86_32 -nostdlib"  -wp -wp-timeout 30 -wp-prover why3:alt-ergo -no-tty -kernel-msg-key pp -no-frama-c-stdlib -wp-fct char_to_clump,read_line src/pr.c "$@" -then -report

cd ../..
echo "=== END ==="