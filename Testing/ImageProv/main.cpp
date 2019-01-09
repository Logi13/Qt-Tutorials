#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

#include "imageprovider.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("colors"), new ImageProvider(QQuickImageProvider::Pixmap));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
