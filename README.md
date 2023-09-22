# Build  

This was working with `QT 6.5.2`, it might not work with newer versions of QT. 
## Windows
First of all make sure to download QT and put `qmake`, `mingw32-make` and `g++` in the PATH environmental variable.

Follow these steps to compile our application and obtain the .exe file :
1. `qmake6 -project QT+=widgets` Creates the .pro file (filename is that of the parent folder's name)
1. `qmake6` Create the MakeFile, it will display a few warnings: that's ok, ignore them
1. `mingw32-make` Executes the MakeFile, compiling .cpp files and linking the QT signals to their slots, using MOC
1. `cd release` This project creates the build files in the 'release' folder
1. `windeployqt.exe [namefile].exe` Deploy the application for Windows, namefile will be the same as the name of the .pro file generated at step 1
## Linux
First of all make sure to install `qt6-base-dev`, `qt6-base-dev-tools`, `g++` and `make` using 'sudo apt install'.

Follow these steps to compile our application and obtain the .out file :
1. `qmake6 -project QT+=widgets` Creates the .pro file (filename is that of the parent folder's name)
1. `qmake6` Create the MakeFile, it will display a few warnings: that's ok, ignore them
1. `make` Executes the MakeFile, compiling .cpp files and linking the QT signals to their slots, using MOC, and deploys the x-executable file (name like name of .pro file)
# Execute
In case of a pc without QT installed (Qt libraries not on PATH), the executive file needs the Qt library files (.dll files) : for portability you have to copy them along with the executive file.
## Windows
Once built the project, inside the 'release' folder there will be the .exe file, that can be run as a normal application, for example by double clicking. 
## Linux
Once built the project, in the main folder, we will find a mess of files, between those we can find the x-executable application, that can be run as a normal application, using ./[name file].
# Clean
There is a python script for the clean-up: `clean-script.py`.

Be careful that this script also removes the build folder, containing the .exe (or .out in Linux).

P.S. : I will probably do bash and bat versions soon
