#include <QtTest>

// add necessary includes here
#include <websocketclient.h>
class WebsocketClientTest : public QObject
{
    Q_OBJECT
public:
    WebsocketClientTest();
    ~WebsocketClientTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();

private:
    WebsocketClient websocketClient;
    QUrl url = QUrl("ws://127.0.0.1:8080/ws");
};

WebsocketClientTest::WebsocketClientTest() {

}

WebsocketClientTest::~WebsocketClientTest() {}

void WebsocketClientTest::initTestCase() {}

void WebsocketClientTest::cleanupTestCase() {}

void WebsocketClientTest::test_case1()
{
    QSignalSpy connectedSpy(&websocketClient, &WebsocketClient::connected);

    websocketClient.connectToServer(url);
    QVERIFY(connectedSpy.wait(1000));
    QCOMPARE(websocketClient.isConnected(), true);


    QSignalSpy disConnectedSpy(&websocketClient, &WebsocketClient::signalDisconnected);

    websocketClient.disconnectFromServer();
    //QVERIFY(disConnectedSpy.wait(5000));
    QTRY_VERIFY_WITH_TIMEOUT(!websocketClient.isConnected(), 4000);
    //QCOMPARE(websocketClient.isConnected(), false);
}

void WebsocketClientTest::test_case2() {
    QVERIFY(true);
}

QTEST_MAIN(WebsocketClientTest)

#include "tst_websocketclienttest.moc"
