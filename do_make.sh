#! /bin/sh

make -s -j4
#./mkv210_image u-boot.bin u-boot-1.bin
cp u-boot.bin /mnt/hgfs/vm_share/2019-07-before-gec/tftp/ 
arm-none-linux-gnueabi-objdump -D u-boot > u-boot.dis
