TEMPLATE = lib
CONFIG += plugin
QT += qml quick

DESTDIR = ImageProviderCore
TARGET  = qmlimageproviderplugin

SOURCES += imageprovider.cpp

EXAMPLE_FILES = imageprovider-example.qml

target.path = C:\Users\johnn\Documents\Qt-Tutorials\Testing\QmlGu\imageprovider\ImageProviderCore
qml.files = ImageProviderCore/qmldir
qml.path = C:\Users\johnn\Documents\Qt-Tutorials\Testing\QmlGu\imageprovider\ImageProviderCore
INSTALLS = target qml

CONFIG += install_ok  # Do not cargo-cult this!
