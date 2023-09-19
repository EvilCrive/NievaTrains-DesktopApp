# Nieva Trains - Desktop Application

# To build
* First off, go inside the correct folder from this repository: `cd qt project` -> `cd NievaTrains_P2`
* `qmake -project` Create the .pro file (add flag qt+=widgets core gui)
* `LINUX` If you have linux :
  * `qmake`
  * `make`
* `WINDOWS` If you have windows :
  * `qmake`
  * `mingw32-make`
  * `mingw32-make install`
  * `cd release`
  * `windeployqt [nomefile].exe`

This was working with QT 5.9.9, I will soon update it for the latest version. 
Apri minGW (qt 5.9.9) e vai sulla directory del progetto

P.S. : A few patches ago of QT, they replaced `qregexpvalidator` and `qregexp` with `qregularexpressionvalidator`
