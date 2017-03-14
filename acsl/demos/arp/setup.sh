rm bugged/ -rf
rm fixed/ -rf

echo "== SETTING UP BUGGED VERSION =="
mkdir bugged
cd bugged
wget https://busybox.net/downloads/busybox-1.6.2.tar.bz2
wait
tar -vxjf busybox-1.6.2.tar.bz2
wait
cd busybox-1.6.2
patch -p1 < ../../bugged.patch
cp ../../.config .config
make
cd ../..


echo "== SETTING UP FIXED VERSION =="
mkdir fixed
cd fixed
wget https://busybox.net/downloads/busybox-1.6.2.tar.bz2
wait
tar -vxjf busybox-1.6.2.tar.bz2
wait
cd busybox-1.6.2
patch -p1 < ../../fixed.patch
cp ../../.config .config
make
cd ../..
