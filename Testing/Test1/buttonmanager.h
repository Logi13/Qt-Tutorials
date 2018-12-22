#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H
#include <QObject>
class ButtonManager : public QObject
{
    Q_OBJECT
    public:
    ButtonManager(QObject* parent = nullptr);
    public slots:
    void onButtonClicked(QString str);
};
#endif // BUTTONMANAGER_H
