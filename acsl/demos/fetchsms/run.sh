if [[ ! -d "bugged" ]]; then
    echo "error: Demo repositories not found. please run setup.sh before this script."
    exit 1
fi

echo "=== BUGGED VERSION ==="

cd bugged/openser-1.1.0-tls &&

frama-c -cpp-command="gcc -g -O9 -minline-all-stringops -mtune=opteron -DNAME='openser' -DVERSION='1.1.1-notls' -DARCH='x86_64' -DOS='linux' -DCOMPILER='gcc 4.6.4' -D__CPU_x86_64 -D__OS_linux -D__SMP_yes -DCFG_DIR='/usr/local/etc/openser/' -DPKG_MALLOC -DSHM_MEM -DSHM_MMAP -DUSE_IPV6 -DUSE_MCAST -DUSE_TCP -DDISABLE_NAGLE -DHAVE_RESOLV_RES -DF_MALLOC -DSTATISTICS -DFAST_LOCK -DADAPTIVE_WAIT -DADAPTIVE_WAIT_LOOPS=1024 -DHAVE_GETHOSTBYNAME2 -DHAVE_UNION_SEMUN -DHAVE_SCHED_YIELD -DHAVE_MSG_NOSIGNAL -DHAVE_MSGHDR_MSG_CONTROL -DHAVE_ALLOCA_H -DHAVE_TIMEGM -DHAVE_EPOLL -DHAVE_SIGIO_RT -DHAVE_SELECT -c -Iframa-c-override -I../../../../libraries/libc/include -D__FC_MACHDEP_X86_64 -C -E" modules/sms/libsms_getsms.c modules/sms/libsms_modem.c -wp -pp-annot -wp-split -wp-fct fetchsms,getsms -no-frama-c-stdlib "$@"

cd ../..

