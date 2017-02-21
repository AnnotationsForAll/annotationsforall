rm bugged/ -rf
rm fixed/ -rf

echo "== SETTING UP BUGGED VERSION =="
mkdir bugged
cd bugged
wget ftp://ftp.gnu.org/gnu/coreutils/coreutils-6.10.tar.gz
wait
tar -xvzf coreutils-6.10.tar.gz
wait
cd coreutils-6.10
patch -p1 < ../../bugged.patch
./configure && make
cd ../..

echo "== SETTING UP FIXED VERSION =="
mkdir fixed
cd fixed
wget ftp://ftp.gnu.org/gnu/coreutils/coreutils-6.10.tar.gz
wait
tar -xvzf coreutils-6.10.tar.gz
wait
cd coreutils-6.10
patch -p1 < ../../fixed.patch
./configure && make
cd ../..

echo "=========================="
echo "The repositories should now be set up. Execute run.sh to start the demo."