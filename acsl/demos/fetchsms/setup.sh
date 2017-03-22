rm bugged/ -rf
rm fixed/ -rf

echo "== SETTING UP BUGGED VERSION =="
mkdir bugged
cd bugged
wget http://www.kamailio.org/pub/openser/1.1.0/src/openser-1.1.0-tls_src.tar.gz
wait
tar -xvzf openser-1.1.0-tls_src.tar.gz
wait
cd openser-1.1.0-tls
patch -p1 < ../../bugged.patch
make
cd ../..


echo "=========================="
echo "The repositories should now be set up. Execute run.sh to start the demo."
