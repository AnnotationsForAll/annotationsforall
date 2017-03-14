if [[ ! -d "bugged" || ! -d "fixed" ]]; then
    echo "error: Demo repositories not found. please run setup.sh before this script."
    exit 1
fi

echo "=== BUGGED VERSION ==="

cd bugged/busybox-1.6.2 &&

frama-c -cpp-command="gcc -C -E -I. -Wp,-MD,networking/.arp.o.d -std=gnu99 -Iinclude -Ilibbb -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D'BB_VER=KBUILD_STR(1.6.2)' -DBB_BT=AUTOCONF_TIMESTAMP -Os -D'KBUILD_STR(s)=#s' -D'KBUILD_BASENAME=KBUILD_STR(arp)'  -D'KBUILD_MODNAME=KBUILD_STR(arp)' -c -I../../../../libraries/libc/include -D__FC_MACHDEP_X86_64 -D__socklen_t_defined -D__GLIBC__ -D__GT_FC_STATFS_DEFINED" -kernel-msg-key pp -wp -wp-fct get_hwtype,arp_main networking/arp.c networking/interface.c libbb/getopt32.c -no-frama-c-stdlib "$@"

cd ../..

echo "=== FIXED VERSION ==="
cd fixed/busybox-1.6.2 &&

frama-c -cpp-command="gcc -C -E -I. -Wp,-MD,networking/.arp.o.d -std=gnu99 -Iinclude -Ilibbb -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D'BB_VER=KBUILD_STR(1.6.2)' -DBB_BT=AUTOCONF_TIMESTAMP -Os -D'KBUILD_STR(s)=#s' -D'KBUILD_BASENAME=KBUILD_STR(arp)'  -D'KBUILD_MODNAME=KBUILD_STR(arp)' -c -I../../../../libraries/libc/include -D__FC_MACHDEP_X86_64 -D__socklen_t_defined -D__GLIBC__ -D__GT_FC_STATFS_DEFINED" -kernel-msg-key pp -wp -wp-fct get_hwtype,arp_main networking/arp.c networking/interface.c libbb/getopt32.c -no-frama-c-stdlib "$@"

cd ../..
echo "=== END ==="