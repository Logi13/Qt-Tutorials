#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/johnn/Documents/Qt-Tutorials/Testing/TestSheet/Picture.png");
    ui->label_pic->setPixmap(pix);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/johnn/Documents/Qt-Tutorials/Testing/TestSheet/classes.db");

    if(!mydb.open())
        ui->label->setText("Failed to open the database");
    else
        ui->label->setText("Connected....");
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_tableLoad_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery(mydb);

    qry->prepare("select * from Fighter");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    //QDebug() << (model->rowCount());
}
*/


void MainWindow::on_loginButton_clicked()
{
    QString username, password;

    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(!mydb.isOpen()) {
        qDebug() << "Failed to open the database";
        return;
    }

    QSqlQuery qry;

    if(qry.exec("select * from fighter where username='"+username +"' and password='"+password+"'" )) {
        int count = 0;
        while(qry.next())
        {
            count++;
        }
        if(count == 1){
            ui->label->setText("username and password is correct");
        }
        else if(count > 1){
            ui->label->setText("Duplicate username and password");
        }
        else if(count < 1){
            ui->label->setText("username and password is not correct");
        }
    }
}
