#!/bin/bash
cd build/out || exit "run this from the gitian-builder directory"
mkdir -p tmp
cd tmp
rm -rf tripone-0.11.2/ triponeUnlimited-0.11.2/
tar xvfz ../tripone-0.11.2-linux64.tar.gz
mv tripone-0.11.2/ triponeUnlimited-0.11.2/
find triponeUnlimited-0.11.2 | sort | tar --no-recursion --mode='u+rw,go+r-w,a+X' --owner=0 --group=0 -c -T - | gzip -9n > ../triponeUnlimited-0.11.2-linux64.tar.gz

rm -rf triponeUnlimited-0.11.2/
tar xvfz ../tripone-0.11.2-linux32.tar.gz
mv tripone-0.11.2/ triponeUnlimited-0.11.2/
find triponeUnlimited-0.11.2 | sort | tar --no-recursion --mode='u+rw,go+r-w,a+X' --owner=0 --group=0 -c -T - | gzip -9n > ../triponeUnlimited-0.11.2-linux32.tar.gz

rm -rf tripone-0.11.2/ triponeUnlimited-0.11.2/

cd ../../..
