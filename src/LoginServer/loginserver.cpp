#include "loginserver.h"
#include "httpservice.h"
#include <QTimer>
#include <QDebug>
LoginServer *LoginServer::getInstance()
{
    static LoginServer loginServer;
    return &loginServer;
}

void LoginServer::handleLogin(const QString &username, const QString &password)
{
    // 调用HttpService的登录接口
    HttpService::getInstance()->loginUser(username, password);
}

void LoginServer::handleResigter(const QString &username, const QString &password, bool async)
{
    // 调用HttpService的注册接口
    // 开始定时器
    if (registerTimer->isActive())
    {
        registerTimer->stop();
    }
    registerTimer->start(4000); // 4秒超时

    HttpService::getInstance()->registerUser(username, password, async);
}


LoginServer::LoginServer(QObject *parent)
    :QObject(parent)
{

    registerTimer = new QTimer(this);
    registerTimer->setSingleShot(true);
    connect(registerTimer, &QTimer::timeout, this, [this]() {
        emit registerFailed("注册超时");
        qInfo() << "注册超时";
        registerTimer->stop();
    });
    connect(HttpService::getInstance(), &HttpService::registerFinished, this, [this](const ServerResult &result) {
        qInfo() << "LoginServer recevied registerFinished signal" << result.success << result.message;
        // 如果超时返回，则不接受
        if (!registerTimer->isActive())
        {
            return;
        }
        registerTimer->stop();
        if (result.success)
        {
            emit registerSuccess();
        } else {
            emit registerFailed(result.message);
        }
    });

}

LoginServer::~LoginServer()
{

}
