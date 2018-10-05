#!/usr/bin/env bash

exit_on_failure() {
    if [ $? -ne 0 ]; then
        echo ""
        echo "build failed"
        exit -1
    fi
}

echo "prepare (1/3): "
mkdir build
cd build
mkdir driver
cp /in/driver/*.* /in/driver/Makefile driver/
exit_on_failure
mkdir mumsh
cp /in/*.* /in/Makefile mumsh/
exit_on_failure
exec 0<> temp0
echo "finished"
echo ""

echo "make (2/3): "
make -C driver
exit_on_failure
make -C mumsh
exit_on_failure
echo "finished"
echo ""

echo "clean (3/3): "
cd ..
mv build/driver/driver .
exit_on_failure
mv build/mumsh/mumsh .
exit_on_failure
mv build/mumsh/mumsh_memory_check .
exit_on_failure
rm -rf build
exit_on_failure
echo "finished"
echo ""

echo "all tasks finished, build successfully"
