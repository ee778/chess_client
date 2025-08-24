#include "loginserver.h"

LoginServer *LoginServer::getInstance()
{
    static LoginServer loginServer;
    return &loginServer;
}

void LoginServer::handleLogin(const QString &username, const QString &password)
{
    // 先做一个简单的判断
    if (username == "admin" && password == "123456")
    {
        emit this->loginSuccess();
    }
    else
    {
        emit this->loginFailed(QString("username or password failed"));
    }
}

void LoginServer::handleResigter(const QString &username, const QString &password)
{

}


LoginServer::LoginServer(QObject *parent)
    :QObject(parent)
{

}

LoginServer::~LoginServer()
{

}
