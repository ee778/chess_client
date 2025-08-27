#include "httpservice.h"
#include "messagebuilder.h"

HttpService::HttpService(IHttpClient *client, QObject *parent)
    :QObject(parent)
{
    m_client = client;
    connect(m_client, &IHttpClient::error, this, &HttpService::processError);
    connect(m_client, &IHttpClient::finished, this, &HttpService::processFinished);
}

HttpService::~HttpService()
{

}

void HttpService::registerUser(QString &userName, QString &password, bool async)
{
    QByteArray byte = MessageBuilder::buildUserRegistrationMessage(userName, password);
    QString url = URL;
    if (async)
    {
        m_client->postAsync(url, byte, "application/json");
    }
    else
    {
        m_client->post(url, byte, "application/json");
    }
}

void HttpService::processError(const QString &err)
{

}

void HttpService::processFinished(const QByteArray &data)
{
    // 处理返回的数据

    // 解析当前返回数据的类型
}
