#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar,SLOT(setValue(int)));

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar_2,SLOT(setValue(int)));

    //disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
    //         ui->progressBar,SLOT(setValue(int)));

    setCentralWidget(ui->plainTextEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_Window_triggered()
{
    mDialog = new MyDialog(this);
    mDialog->show();
}
