#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <LoginServer/loginserver.h>
#include "appstartup.h"
#include "global.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    if (AppStartup::getInstance()->startup() == false)
    {
        return -1;
    }

    // 注册C++类到QML
    //qmlRegisterType<LoginServer>("com.chessclient.login", 1, 0, "LoginServer");

    QQuickStyle::setStyle("Material");

    //使用setContextProperty
    QQmlApplicationEngine engine;
    auto loginServer = LoginServer::getInstance();
    engine.rootContext()->setContextProperty("LoginServer", loginServer);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("chess_client", "Main");

    if (loginServer != nullptr && loginServer->getLoginStatus() == LoginStatus::LOGINED)
    {
        // 已经登录，发送退出登陆
        loginServer->handleLogout();
    }
    return app.exec();
}
