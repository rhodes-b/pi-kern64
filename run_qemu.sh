#!/bin/sh
cd bin
qemu-system-aarch64 -M raspi3b -serial stdio -kernel kernel8.elf
# note -bios should let us use kernel8.img but not rn?
cd ..
