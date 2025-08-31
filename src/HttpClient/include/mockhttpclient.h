#ifndef MOCKHTTPCLIENT_H
#define MOCKHTTPCLIENT_H

#include "IHttpClient.h"

class MockHttpClient : public IHttpClient
{
    Q_OBJECT
public:
    explicit MockHttpClient(QObject *parent = nullptr);

    ~MockHttpClient();

    QByteArray get(const QString &url) override;
    QByteArray post(const QString &url, const QByteArray &data, const QString &contentType) override;

    void getAsync(const QString &url) override;

    void postAsync(const QString &url, const QByteArray &data, const QString &contentType) override;
public:
    QByteArray lastPostData;
    QString lastUrl;
};

#endif // MOCKHTTPCLIENT_H
