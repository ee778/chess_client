#include "httpservice.h"
#include "messagebuilder.h"
#include "messageparser.h"
#include "global.h"
#include <QDebug>
HttpService::HttpService(IHttpClient *client, QObject *parent)
    :QObject(parent)
{
    if (client != nullptr)
    {
        m_client = client;
        connect(m_client, &IHttpClient::error, this, &HttpService::processError);
        connect(m_client, &IHttpClient::finished, this, &HttpService::processFinished);
    }
}

bool HttpService::setHttpClient(IHttpClient *client)
{
    if (client == nullptr)
    {
        return false;
    }
    m_client = client;
    connect(m_client, &IHttpClient::error, this, &HttpService::processError);
    connect(m_client, &IHttpClient::finished, this, &HttpService::processFinished);
    return true;
}

HttpService::~HttpService()
{

}

void HttpService::registerUser(const QString &userName, const QString &password, bool async)
{
    QByteArray byte = MessageBuilder::buildUserRegistrationMessage(userName, password);
    QString url = URL + "/api/register";
    if (async)
    {
        m_client->postAsync(url, byte, "application/json");
    }
    else
    {
        auto data = m_client->post(url, byte, "application/json");
        ServerResult result = MessageParser::parseServerResponse(data);
        emit registerFinished(result);
    }
}

void HttpService::loginUser(const QString &userName, const QString &password, bool async)
{

}

void HttpService::processError(const QString &err)
{
    // 会在这里接收到失败的信息
    qInfo() << "HttpService::processError" << err;

}

void HttpService::processFinished(const QByteArray &data)
{
    // 处理返回的数据
    qInfo() << "HttpService::processFinished" << data;
    auto result = MessageParser::parseServerResponse(data);
    if (result.serverData.type == MessageType::REGISTER)
    {
        qInfo() << "emit registerFinished";
        emit registerFinished(result);
    }

}
