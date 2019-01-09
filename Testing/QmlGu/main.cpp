#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QThread>

#include "imageprovider.h"
#include "complex.h"


int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("imageprovider"),
                            new ImageProvider(QQuickImageProvider::Pixmap));
    engine.load("qrc:/main.qml");
    return app.exec();
}
