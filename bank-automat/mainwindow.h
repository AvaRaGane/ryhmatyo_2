#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <login.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum State {
        SELECT_CARD,
        CARD_FAIL,
        CARD_OK,
        PIN_OK,
        PIN_ATTEMPT_1,
        PIN_ATTEMPT_2,
        PIN_ATTEMPT_3,
        CARD_LOCKED,
        SELECT_ACCOUNT,
        CARD_COMBINATION,
        CARD_MANYDEBITS,
        CARD_ADMIN,
        CARD_CREDIT,
        CARD_DEBIT,
        SELECT_DEBIT,
        SELECT_CREDIT,
        SELECT_ADMIN,
        USER_LOGIN,
        ADMIN_LOGIN,
        USER_MENU,
        ADMIN_MENU,
        USER_TRANSACTIONS,
        USER_BALANCE,
        USER_WITHDRAWAL,
        AUTOMAT_ADD_MONEY,
        AUTOMAT_SET_MAX_WITHDRAWAL,
        AUTOMAT_VIEW_LOG,
        CONFIRM,
        LOGOUT
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Login *getLoginView() const;

public slots:
    void clickedNumberHandler();
    void clickedGREEN();
    void clickedYELLOW();
    void clickedGREY();
    void clickedRED();
    void showLogin();
    void showInputPin(QString cardType);
    void selectDebitCredit();
    void showMenu();


private:
    Ui::MainWindow *ui;
    QNetworkReply * reply;
    QNetworkAccessManager *manager;
    QString ID;
    QString pin;
    void connectSlots();
    QString cardType;
    void requestID();
    void requestLogin();
    int state;
    Login * login;

};
#endif // MAINWINDOW_H
