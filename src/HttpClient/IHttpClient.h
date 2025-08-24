#ifndef IHTTPCLIENT_H
#define IHTTPCLIENT_H
#include <QObject>

class IHttpClient: public QObject {
    Q_OBJECT
public:
    explicit IHttpClient(QObject *parent = nullptr) :QObject(parent){}

    virtual QByteArray get(const QString &url) = 0;
    virtual QByteArray post(const QString &url, const QByteArray &data, const QString &contentType = "application/json") = 0;

    // 非阻塞， 使用信号槽
    virtual void getAsync(const QString &url) = 0;
    virtual void postAsync(const QString &url, const QByteArray &data, const QString &Type= "application/json") = 0;

signals:
    void finished(const QByteArray &data);
    void error(const QString &err);
};

#endif // IHTTPCLIENT_H
