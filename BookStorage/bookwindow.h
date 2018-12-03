#ifndef BOOKWINDOW_H
#define BOOKWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtSql>
#include "ui_bookwindow.h"

namespace Ui {
class bookwindow;
}

class bookwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit bookwindow(QWidget *parent = nullptr);
    ~bookwindow();

private:
    void showError(const QSqlError &err);
    Ui::bookwindow *ui;
    QSqlRelationalTableModel *model;
    int authorIdx, genreIdx;

    void createMenuBar();
};

#endif // BOOKWINDOW_H
