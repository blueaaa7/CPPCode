QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FaceDetection.cpp \
    main.cpp \
    Widget.cpp

HEADERS += \
    FaceDetection.h \
    Widget.h

FORMS += \
    Widget.ui
    
INCLUDEPATH +=F:\opencv\opencv\opencv-build\install\include
LIBS +=F:\opencv\opencv\opencv-build\lib\libopencv_*.dll.a

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
