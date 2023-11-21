#ifndef CHECKBALANCE_H
#define CHECKBALANCE_H

#include <QObject>
#include <QWidget>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QPushButton>
#include <QTimer>
#include <QByteArray>
#include <QJsonObject>

class CheckBalance : public QObject
{
    Q_OBJECT
public:
    explicit CheckBalance(QObject* parent = nullptr);
    ~CheckBalance();
    void requestBalance(QString token, QString accountID);
    void displayBalance(QString, QString);
    QList<QString> getBalance();
public slots:
    void handleGetBalance();
signals:
    void balanceReady(QString balance);
    void userBalance();

private:

    void parseBalance(const QString &data);
    QString token;
    QString accountID;
    QString cardID;
    int offset;
    QString saldo;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QString returnedTransactions;
    QList<QString> parsedTransactions;
    QList<QString> parsedBalance;
    int maximumTransactions;
};

#endif // CHECKBALANCE_H

