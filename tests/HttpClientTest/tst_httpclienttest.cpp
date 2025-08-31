#include <QtTest/QtTest>
#include "httpservice.h"
#include "mockhttpclient.h"
#include "messageparser.h"
#include <QSignalSpy>
class TestHttpService: public QObject {
    Q_OBJECT
private slots:
    void testRegisterUserSync() {
        MockHttpClient client;
        HttpService service(&client);
        QSignalSpy spy(&client, &IHttpClient::finished);

        // Simulate a synchronous POST request
        QString userName = "admin";
        QString password = "123456";
        service.registerUser(userName, password, true);

        QCOMPARE(spy.count(), 1);
    }

    void testMessageParserSuccess();

    void testmessageParserFail();
};

QTEST_MAIN(TestHttpService)
#include "tst_httpclienttest.moc"

void TestHttpService::testMessageParserSuccess()
{
    QByteArray jsonResponse = R"(
    {   "success": true,
        "code": 200,
        "message": "OK",
        "data": {
            "type": 1000
        }
    })";
    ServerResult result = MessageParser::parseServerResponse(jsonResponse);
    QCOMPARE(result.success, true);
    QCOMPARE(result.code, 200);
    QCOMPARE(result.message, QString("OK"));
    QCOMPARE(result.serverData.type, 1000);
}

void TestHttpService::testmessageParserFail()
{
    // 1. json 格式不完整
    QByteArray jsonResponse1 = R"(
    {   "success": true,
        "code": 200,
        "message": "OK",
        "data": {
            "type": 1000
        }
    )"; // 缺少结束括号
    ServerResult result1 = MessageParser::parseServerResponse(jsonResponse1);
    QCOMPARE(result1.success, false);
    // 2. 缺少 code 字段
    QByteArray jsonResponse2 = R"(
    {   "success": true,
        "message": "OK",
        "data": {
            "type": 1000
        }
    })";
    ServerResult result2 = MessageParser::parseServerResponse(jsonResponse2);
    QCOMPARE(result1.success, false);
}
