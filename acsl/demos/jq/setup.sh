rm bugged/ -rf
rm fixed/ -rf

echo "== SETTING UP BUGGED VERSION =="
git init bugged
cd bugged
git remote add origin https://github.com/stedolan/jq.git
git fetch
git reset --hard 89897b4bcd7e2fbbe3fade3bd05fd39c712cc05f
git am ../bugged.patch
cd ..

echo "== SETTING UP FIXED VERSION =="
git init fixed
cd fixed
git remote add origin https://github.com/stedolan/jq.git
git fetch
git reset --hard 0b8218515eabf1a967eba0dbcc7a0e5ae031a509
git am ../fixed.patch
cd ..

echo "=========================="
echo "The repositories should now be set up. Execute run.sh to start the demo."