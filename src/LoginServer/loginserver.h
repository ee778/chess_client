#ifndef LOGINSERVER_H
#define LOGINSERVER_H
#include <QObject>
#include "global.h"
class QTimer;
class LoginServer: public QObject
{
    Q_OBJECT
public:
    static LoginServer *getInstance();

    ~LoginServer();

    LoginStatus getLoginStatus() const { return m_loginStatus; }
private:
    explicit LoginServer(QObject *parent = nullptr);
    LoginServer(LoginServer &) = delete;
    LoginServer &operator=(const LoginServer &) = delete;
public slots:
    void handleLogin(const QString &username, const QString &password);

    void handleRegister(const QString &username, const QString &password, bool async = false);

    void handleLogout();
signals:
    void loginSuccess();
    void loginFailed(const QString &errorMessage);

    void registerSuccess();
    void registerFailed(const QString &errorMessage);
private:
    QTimer *loginTimer = nullptr;
    QTimer *registerTimer = nullptr;
    LoginStatus m_loginStatus = LoginStatus::LOGOUT;
    QString m_token; // 登录成功后的token
};

#endif // LOGINSERVER_H
