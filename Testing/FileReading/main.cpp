#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString filename = "C:/Users/johnn/Documents/Qt-Tutorials/Testing/FileReading/file.txt";
    //file operation
    QFile file( filename);
    if(file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream stream( &file );
        stream << "something" << endl;
    }
    return a.exec();
}
