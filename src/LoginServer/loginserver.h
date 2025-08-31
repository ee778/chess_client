#ifndef LOGINSERVER_H
#define LOGINSERVER_H
#include <QObject>

class QTimer;
class LoginServer: public QObject
{
    Q_OBJECT
public:
    static LoginServer *getInstance();

    ~LoginServer();

private:
    explicit LoginServer(QObject *parent = nullptr);
    LoginServer(LoginServer &) = delete;
    LoginServer &operator=(const LoginServer &) = delete;
public slots:
    void handleLogin(const QString &username, const QString &password);

    void handleResigter(const QString &username, const QString &password, bool async = false);
signals:
    void loginSuccess();
    void loginFailed(const QString &errorMessage);

    void registerSuccess();
    void registerFailed(const QString &errorMessage);
private:
    QTimer *loginTimer = nullptr;
    QTimer *registerTimer = nullptr;
};

#endif // LOGINSERVER_H
