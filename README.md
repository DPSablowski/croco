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

# With Qt Creator

Download the Qt creator and a qt library from the website.

Some additional libraries are required, e.g. on Ubuntu:

sudo apt-get install libglu1-mesa-dev* armadillo* openBLAS* CCfits*

You also need the spline.h from: http://kluge.in-chemnitz.de/opensource/spline/

copy it to /usr/include/

You can load the .pro file with the Qt creator:
If a message box pops up, klick ok then click "configure project". If done, click the "play" button left bottom corner of the Qt creator.

