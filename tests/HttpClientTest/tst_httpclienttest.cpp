#include <QtTest/QtTest>
#include "httpservice.h"
#include "mockhttpclient.h"
#include <QSignalSpy>
class TestHttpService: public QObject {
    Q_OBJECT
private slots:
    void testSendUserInfoSync() {


        MockHttpClient client;
        HttpService service(&client);
        QSignalSpy spy(&client, &IHttpClient::finished);

        QString url = "http://example.com/api/user";
        QByteArray data = R"({"name": "John", "age": 30})";

        // Simulate a synchronous POST request
        QString userName = "admin";
        QString password = "123456";
        service.registerUser(userName, password);


        QCOMPARE(spy.count(), 1);
    }
};

QTEST_MAIN(TestHttpService)
#include "tst_httpclienttest.moc"
