#include "bookwindow.h"
#include <QApplication>
#include <QtWidgets>


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(books);

    QApplication app(argc, argv);

    bookwindow w;
    w.show();

    return app.exec();
}
