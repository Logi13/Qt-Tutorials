QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    imageProvider.cpp \
    complex.cpp

RESOURCES += qml.qrc

DEFINES += QT_DEPRECATED_WARNINGS

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += imageProvider.h \
    complex.h
