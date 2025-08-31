#include <QtTest>

// add necessary includes here
#include "loginserver.h"
#include "httpclient.h"
#include "httpservice.h"
class tst_LoginServer : public QObject
{
    Q_OBJECT

public:
    tst_LoginServer();
    ~tst_LoginServer();

private slots:
    void test_case1();

private:
    LoginServer *loginServer = LoginServer::getInstance();
    const QString testUserName = "testUser10";
    const QString testPassword = "testPassword";

    IHttpClient *client;
};

tst_LoginServer::tst_LoginServer() {
    // 初始化httpServer
    client = new HttpClient();
    HttpService::getInstance()->setHttpClient(client);
}

tst_LoginServer::~tst_LoginServer() {}

void tst_LoginServer::test_case1() {
    // 设置信号spy
    QSignalSpy successSpy(loginServer, &LoginServer::registerSuccess);
    QSignalSpy failedSpy(loginServer, &LoginServer::registerFailed);

    // 随机创建userName和password

    loginServer->handleResigter(testUserName, testPassword, true);


    // 等待信号
    QVERIFY(!failedSpy.wait(5000));  // 如果在5秒内没有收到返回信号，则算成功
    QCOMPARE(successSpy.count(), 1);
}

QTEST_MAIN(tst_LoginServer)

#include "tst_tst_loginserver.moc"
