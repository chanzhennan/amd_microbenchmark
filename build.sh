# Remove the previous 'build' directory and create a new one
rm -rf build
mkdir build && cd build

## CUDA Platform ###########
# cmake -DBUILD_WITH_CUDA=ON -DARCH=sm_80 ..

## HIP Platform ############
# cmake -DBUILD_WITH_MI210=ON ..
#
# cmake -DBUILD_WITH_RX7900=ON ..

## MX Platform ############
#

cmake -DBUILD_WITH_RX7900=ON ..
make -j
