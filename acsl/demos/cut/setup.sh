rm bugged/ -rf
rm fixed/ -rf

echo "== SETTING UP BUGGED VERSION =="
git init bugged
cd bugged
git remote add origin git://git.sv.gnu.org/coreutils.git
wait
git fetch
wait
git reset --hard d57ebc45ba4c59cc6f8bb0e9a435ecbddc84b982
wait
./bootstrap && ./configure && make
patch -p0 < ../bugged.patch
cd ..

echo "== SETTING UP FIXED VERSION =="
git init fixed 
cd fixed
git remote add origin git://git.sv.gnu.org/coreutils.git
wait
git fetch
wait
git reset --hard be7932e863de07c4c7e4fc3c1db3eb6d04ba9af5
wait
./bootstrap && ./configure && make
patch -p0 < ../fixed.patch
cd ..

echo "=========================="
echo "The repositories should now be set up. Execute run.sh to start the demo."
