#include <QCoreApplication>
#include <QtCore>
#include <QFile>
#include <QTextStream>
#include <QStringList>

// text stream is text-codec aware
QTextStream cout(stdout, QIODevice::WriteOnly);
int main(int argc, char *argv[])
{
    //Avoid Compiler warnings
    Q_UNUSED(argc)
    Q_UNUSED(argv)
    QString s1("Paris");
    QString s2("London");
    //String concatentation
    QString s = s1 + " " + s2 + "!";
    cout << s << endl;

    //File IO
    QFile ifile("in.txt");
    ifile.open(QIODevice::ReadOnly | QIODevice::Text);

    // read whole content
    QString content = ifile.readAll();
    //extract words
    QStringList list = content.split(" ");

    QFile ofile("out.txt");
    ofile.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(&ofile);

    //join QStringList by "\n" to write each single word in an own line
    out << list.join("\n");

    ofile.close();
}
