#include "mainwindow.h"
#include "login.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    login = new Login (this);
    showLogin();

    manager = new QNetworkAccessManager(this);
    reply = nullptr;

    connectSlots();

    ui->pushButton1->setDisabled(true);
    ui->pushButton2->setDisabled(true);
    ui->pushButton3->setDisabled(true);
    ui->pushButton4->setDisabled(true);
    ui->pushButton5->setDisabled(true);
    ui->pushButton6->setDisabled(true);
    ui->pushButton7->setDisabled(true);
    ui->pushButton8->setDisabled(true);

    ui->RED->setDisabled(false);
    ui->YELLOW->setDisabled(false);
    ui->GREY->setDisabled(false);
    ui->GREEN->setDisabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickedNumberHandler()
{
    QPushButton * btn = qobject_cast<QPushButton*>(sender());
    QString name = btn->objectName();
    qDebug()<< name << " -button clicked";

    QString content = ui->Content->text();
    content.append(name.last(1));
    ui->Content->setText(content);
}

void MainWindow::clickedGREEN()
{
    qDebug()<<"Green button clicked";
    login->setCardID(ui->Content->text());
}

void MainWindow::clickedYELLOW()
{
    qDebug()<<"Yellow button clicked";
    ui->Content->clear();
}

void MainWindow::clickedGREY()
{
    qDebug()<<"Grey button clicked";

    QString content = ui->Content->text();
    if (content.size() > 0) {
        ui->Content->setText(content.left(content.size() -1));
    }
}

void MainWindow::clickedRED()
{
    qDebug()<<"Red button clicked";
    showLogin();
}

void MainWindow::showLogin()
{
    ui->Title->setText("Kirjaudu sisään");
    ui->Title->setAlignment(Qt::AlignCenter);
    ui->SecondTitle->setText(QString("Syötä kortin ID"));
    ui->Content->clear();
}

void MainWindow::showInputPin(QString cardType)
{
    ui->Title->setText(QString("Kortti tunnistettu"));
    ui->SecondTitle->setText(QString("Syötä pin"));
    ui->Content->clear();
}

void MainWindow::connectSlots()
{
    for(int i = 0; i <= 9; i++) {
        QString btnName = "N" + QString::number(i);
        QPushButton * btn = this->findChild<QPushButton*>(btnName);
        if(btn) {
            connect(btn, SIGNAL(clicked()),this, SLOT(clickedNumberHandler()));
        }
    }
    connect(ui->RED, SIGNAL(clicked()),this, SLOT(clickedRED()));
    connect(ui->YELLOW, SIGNAL(clicked()),this, SLOT(clickedYELLOW()));
    connect(ui->GREY, SIGNAL(clicked()),this, SLOT(clickedGREY()));
    connect(ui->GREEN, SIGNAL(clicked()),this, SLOT(clickedGREEN()));
    connect(login, SIGNAL(cardOk(QString)), this, SLOT(showInputPin(QString)));
}
