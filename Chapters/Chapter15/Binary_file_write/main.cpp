#include <QCoreApplication>
#include <read_write.cpp>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    read_func();

    //we do not start the eventloop as this would wait for external IO
    //app.exec();

    //no need to close file, closes automaticaly when scope ends
    return 0;
}


