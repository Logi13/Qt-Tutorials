#include <QFile>
#include <QDir>
#include <QDataStream>
#include <QDebug>
#include <QtTest/QTest>

void read_func() {

    // write a binary file
    QStringList data({"a", "b", "c"});
    {
         //write binary files
        QFile file(QDir::home().absoluteFilePath("out.bin"));
        if(file.open(QIODevice::WriteOnly)) {
            QDataStream out(&file);
            out << data;
        }
    }
    // read a binary file
    {
        QFile file(QDir::home().absoluteFilePath("out.bin"));
        if(file.open(QIODevice::ReadOnly)) {
            QDataStream stream(&file);
            QStringList data2;
            stream >> data2;
            //QCOMPARE(data, data2);
        }
    }

}
