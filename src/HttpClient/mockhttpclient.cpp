#include "mockhttpclient.h"
#include <QJsonDocument>
#include <QJsonObject>
MockHttpClient::MockHttpClient(QObject *parent)
    : IHttpClient{parent}
{}

MockHttpClient::~MockHttpClient()
{

}

QByteArray MockHttpClient::get(const QString &url)
{
    lastUrl = url;
    return R"({"success": true, "message": "Mock GET OK"})";
}

QByteArray MockHttpClient::post(const QString &url, const QByteArray &data, const QString &contentType)
{
    Q_UNUSED(contentType);

    lastUrl = url;
    lastPostData = data;
    return R"({"success": true, "message": "Async Get Ok"})";
}

void MockHttpClient::getAsync(const QString &url)
{
    emit finished(R"({"success": true, "message": "Async GET OK"})");
}

void MockHttpClient::postAsync(const QString &url, const QByteArray &data, const QString &contentType)
{
    Q_UNUSED(contentType);

    lastUrl = url;
    lastPostData = data;
    QJsonDocument jsonData = QJsonDocument::fromJson(data);
    if (!jsonData.isNull() && jsonData.isObject())
    {
        QJsonObject jsonObj = jsonData.object();
        if (jsonObj.contains("type") && jsonObj["type"].isDouble())
        {
            int type = jsonObj["type"].toInt();
            if (type == 1000)
            {
                emit finished(R"({
                "code": 201,
                "message": "success",
                "data" : {
                    "type": 1000
                }
                })");
                return;
            }
        }
    }

    //emit finished(R"("success": true, "message": "Async POST OK")");
}




