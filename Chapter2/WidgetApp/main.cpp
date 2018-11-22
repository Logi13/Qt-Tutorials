#include <QCoreApplication>
#include <QtGui>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QScopedPointer<QWidget> widget(new CustomWidget());
    widget->resize(240, 120);
    widget->show();
    return app.exec();
}
