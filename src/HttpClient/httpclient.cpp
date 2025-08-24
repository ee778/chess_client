#include "httpclient.h"
#include <QDebug>
HttpClient::HttpClient(QObject *parent)
    :IHttpClient(parent)
{
    initConnect();
}

QByteArray HttpClient::get(const QString &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = m_manager.get(request);

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec(); // 阻塞等待

    QByteArray data;

    if (reply->error() == QNetworkReply::NoError)
    {
        data = reply->readAll();
    }
    else {
        qWarning() << "Get Error" << reply->errorString();
    }

    reply->deleteLater();
    return data;
}

QByteArray HttpClient::post(const QString &url, const QByteArray &data, const QString &contentType)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, contentType);

    QNetworkReply *reply = m_manager.post(request, data);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QByteArray response;
    if (reply->error() == QNetworkReply::NoError)
    {
        response = reply->readAll();
    }
    else
    {
        qWarning() << "POST error" << reply->error();
    }

    reply->deleteLater();
    return response;
}

void HttpClient::getAsync(const QString &url)
{
    QNetworkRequest req(url);
    m_manager.get(req);
}

void HttpClient::postAsync(const QString &url, const QByteArray &data, const QString &Type)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, Type);
    m_manager.post(request, data);
}

void HttpClient::initConnect()
{
    connect(&m_manager, &QNetworkAccessManager::finished,
            this, &HttpClient::onReplyFinished);
}

void HttpClient::onReplyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        emit finished(reply->readAll());

    }
    else
    {
        emit error(reply->errorString());
    }
    reply->deleteLater();
}
