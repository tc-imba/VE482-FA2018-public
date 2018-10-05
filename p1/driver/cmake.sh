#!/usr/bin/env bash

exit_on_failure() {
    if [ $? -ne 0 ]; then
        echo ""
        echo "build failed"
        exit -1
    fi
}

echo "prepare (1/4): "
mkdir build
cd build
exec 0<> temp0
echo "finished"
echo ""

echo "cmake (2/4): "
cmake -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ /in/driver
exit_on_failure
echo "finished"
echo ""

echo "make (3/4): "
make
exit_on_failure
echo "finished"
echo ""

echo "clean (4/4): "
cd ..
mv build/driver .
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
