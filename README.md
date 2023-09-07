# predict-mech
export CROSS_COMPILE=/home/daniel/toolchains/arm/gcc-arm-11.2-2022.02-x86_64-arm-none-eabi/bin/arm-none-eabi-

# st 
make clean && make && make flash
odd parity, 7bytes


## nxp
 make clean && make && while ! make flash; do sleep 1; done