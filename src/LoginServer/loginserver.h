#ifndef LOGINSERVER_H
#define LOGINSERVER_H
#include <QObject>

class LoginServer: public QObject
{
    Q_OBJECT
public:
    LoginServer *getInstance();
    explicit LoginServer(QObject *parent = nullptr);
    ~LoginServer();

public slots:
    void handleLogin(const QString &username, const QString &password);

    void handleResigter(const QString &username, const QString &password);
signals:
    void loginSuccess();
    void loginFailed(const QString &errorMessage);
private:





};

#endif // LOGINSERVER_H
