echo compile...
arm-none-eabi-g++ -std=c++23 -march=armv7e-m -S -O$1 test1.cc -I../inc/XSPL -I../inc/
arm-none-eabi-g++ -std=c++23 -c -O$1 test1.cc -I../inc/XSPL -I../inc/
