# CroCo
CroCo - 2dim cross-correlation

# installation

Written in C++ with the Qt Creator. All files are stored in the folder CroCo.

you can run the command

objdump -p CroCo | grep NEEDED

to find the necessary libraries; you may have to install some of them:

libcfitsio.so.2

libCCfits.so.0

libstdc++.so.6

libQt5PrintSupport.so.5

libQt5Widgets.so.5

libQt5Gui.so.5

libQt5Core.so.5

libGL.so.1

libpthread.so.0

libm.so.6

libgcc_s.so.1

libc.so.6

to run the program: ./CroCo
