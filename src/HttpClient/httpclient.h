#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include "IHttpClient.h"
class HttpClient: public IHttpClient
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);
    ~HttpClient();

    // 同步接口
    QByteArray get(const QString &url);
    QByteArray post(const QString &url, const QByteArray &data, const QString &contentType = "application/json");

    // 非阻塞， 使用信号槽
    void getAsync(const QString &url);
    void postAsync(const QString &url, const QByteArray &data, const QString &Type= "application/json");

private slots:
    void onReplyFinished(QNetworkReply *reply);
private:
    void initConnect();
private:
    QNetworkAccessManager m_manager;
};

#endif // HTTPCLIENT_H
