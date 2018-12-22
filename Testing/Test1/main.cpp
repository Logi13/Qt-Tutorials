#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

#include "buttonmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlComponent component(&engine, QUrl(QLatin1String("qrc:/main.qml")));
    QObject *mainPage = component.create();
    QObject* item = mainPage->findChild<QObject *>("buttonTest");
    ButtonManager buttonManager(mainPage);
    QObject::connect(item, SIGNAL(clickedButton(QString)), &buttonManager,
    SLOT(onButtonClicked(QString)));
    return app.exec();
}
