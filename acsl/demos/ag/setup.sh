rm bugged/ -rf
rm fixed/ -rf

echo "== SETTING UP BUGGED VERSION =="
git init bugged
cd bugged
git remote add origin https://github.com/ggreer/the_silver_searcher.git
git fetch
git reset --hard de7ee68c665f705ef0cdb7044301d2661a9291f9
git am ../bugged.patch
./build.sh
cd ..

echo "== SETTING UP FIXED VERSION =="
git init fixed
cd fixed
git remote add origin https://github.com/ggreer/the_silver_searcher.git
git fetch
git reset --hard 7d3e02f452964294f6835362391a113838dafa59
git am ../fixed.patch
./build.sh
cd ..

echo "=========================="
echo "The repositories should now be set up. Execute run.sh to start the demo."