#include <QCoreApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QWidget *window = new QWidget;

    window->show();
    return app.exec();
}
