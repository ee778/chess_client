#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <LoginServer/loginserver.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // 注册C++类到QML
    qmlRegisterType<LoginServer>("com.chessclient.login", 1, 0, "LoginServer");

    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("chess_client", "Main");

    return app.exec();
}
