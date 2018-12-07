#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/johnn/Documents/Qt-Tutorials/Testing/Sheet/Picture.png");
    ui->label_pic->setPixmap(pix);

    if(!connOpen())
        ui->label->setText("Failed to open the database");
    else
        ui->label->setText("Connected....");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username, password;

    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(!connOpen()) {
        qDebug() << "Failed to open the database";
        return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from fighter where username='"+username +"' and password='"+password +"'");

    if(qry.exec()) {
        int count = 0;
        while(qry.next())
        {
            count++;
        }
        if(count == 1){
            ui->label->setText("username and password is correct");
            connClose();
        }
        else if(count > 1){
            ui->label->setText("Duplicate username and password");
        }
        else if(count < 1){
            ui->label->setText("username and password is not correct");
        }
    }
}

void MainWindow::on_pushButton_tableLoad_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    connOpen();
    QSqlQuery *qry = new QSqlQuery(mydb);

    qry->prepare("select Level,Skills,Description from fighter");

    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    qDebug() << (model->rowCount());

    connClose();
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString cl = ui->comboBox->currentText();

    if (cl == "Fighter"){
        QSqlQueryModel *model = new QSqlQueryModel();
        connOpen();
        QSqlQuery *qry = new QSqlQuery(mydb);

        qry->prepare("select Level,Skills,Description from fighter");

        qry->exec();
        model->setQuery(*qry);
        ui->tableView->setModel(model);
        qDebug() << (model->rowCount());

        connClose();
    } else if(cl == "Shaper"){
        QSqlQueryModel *model = new QSqlQueryModel();
        connOpen();
        QSqlQuery *qry = new QSqlQuery(mydb);

        qry->prepare("select Level,Skills,Description from shaper");

        qry->exec();
        model->setQuery(*qry);
        ui->tableView->setModel(model);
        qDebug() << (model->rowCount());

        connClose();
    } else if(cl == "Hunter"){
        QSqlQueryModel *model = new QSqlQueryModel();
        connOpen();
        QSqlQuery *qry = new QSqlQuery(mydb);

        qry->prepare("select Level,Skills,Description from hunter");

        qry->exec();
        model->setQuery(*qry);
        ui->tableView->setModel(model);
        qDebug() << (model->rowCount());

        connClose();
    }
}
