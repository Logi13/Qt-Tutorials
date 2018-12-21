TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

include(deployment.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    flags/22px-Flag_of_Cote_d'Ivoire.svg.png \
    flags/22px-Flag_of_Egypt.svg.png \
    flags/22px-Flag_of_Germany.svg.png \
    flags/22px-Flag_of_India.svg.png \
    flags/22px-Flag_of_Indonesia.svg.png \
    flags/22px-Flag_of_Iran.svg.png \
    flags/22px-Flag_of_Iraq.svg.png \
    flags/22px-Flag_of_Japan.svg.png \
    flags/22px-Flag_of_Kenya.svg.png \
    flags/22px-Flag_of_Mexico.svg.png \
    flags/22px-Flag_of_Myanmar.svg.png \
    flags/22px-Flag_of_Nigeria.svg.png \
    flags/22px-Flag_of_North_Korea.svg.png \
    flags/22px-Flag_of_Pakistan.svg.png \
    flags/22px-Flag_of_Peru.svg.png \
    flags/22px-Flag_of_Russia.svg.png \
    flags/22px-Flag_of_Saudi_Arabia.svg.png \
    flags/22px-Flag_of_Singapore.svg.png \
    flags/22px-Flag_of_South_Africa.svg.png \
    flags/22px-Flag_of_South_Korea.svg.png \
    flags/22px-Flag_of_Spain.svg.png \
    flags/22px-Flag_of_Thailand.svg.png \
    flags/22px-Flag_of_the_Democratic_Republic_of_the_Congo.svg.png \
    flags/22px-Flag_of_the_People's_Republic_of_China.svg.png

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lfileio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lfileiod
else:unix: LIBS += -L$$PWD/./ -lfileio

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
