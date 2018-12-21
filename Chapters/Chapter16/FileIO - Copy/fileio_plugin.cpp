#include "fileio_plugin.h"
#include "fileio.h"

#include "qqml.h"

void FileIO_Plugin::registerTypes(const char *uri)
{
    // @uri org.example.io
    qmlRegisterType<FileIO>(uri, 1, 0, "FileIO");
}
