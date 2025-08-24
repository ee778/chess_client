#ifndef MOCKHTTPCLIENT_H
#define MOCKHTTPCLIENT_H

#include "IHttpClient.h"

class MockHttpClient : public IHttpClient
{
    Q_OBJECT
public:
    explicit MockHttpClient(QObject *parent = nullptr);
};

#endif // MOCKHTTPCLIENT_H
