#ifndef HTTPSERVICE_H
#define HTTPSERVICE_H
#include <QObject>
#include "IHttpClient.h"
class HttpService: public QObject
{
    Q_OBJECT
public:
    HttpService(IHttpClient *client, QObject *parent = nullptr);
    ~HttpService();

private:
    IHttpClient *m_client;
};

#endif // HTTPSERVICE_H
