#include "ButtonManager.h"
#include <QDebug>
ButtonManager::ButtonManager(QObject *parent)
: QObject(parent)
{
}
void ButtonManager::onButtonClicked(QString str)
{
    qDebug() << "button: " << str;
}
