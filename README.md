# predict-mech
export CROSS_COMPILE=/home/daniel/toolchains/arm/gcc-arm-11.2-2022.02-x86_64-arm-none-eabi/bin/arm-none-eabi-

# st
make clean && make && make flash
odd parity, 7bytes

## nxp
 make clean && make && while ! make flash; do sleep 1; done

# tpa_cfg.py
## to generate the empty tpa_cfg.c from the tmg.json
python3 src/lib/tpa_mech/tpa_cfg.py -g empty -i src/config/lpc55s69/tpa/tmg.json

## to generate the filled tpa_cfg.c from the profiling output
python3 src/lib/tpa_mech/tpa_cfg.py -g filled -i src/config/lpc55s69/tpa/serial.txt