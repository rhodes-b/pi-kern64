#!/bin/sh

cd ./bin
qemu-system-arm -M raspi2b -serial stdio -kernel kernel7.elf
cd ..
