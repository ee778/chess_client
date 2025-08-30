#ifndef MESSAGEPARSER_H
#define MESSAGEPARSER_H

#include <QObject>
#include "../Utils/global.h"

struct ServerResult;
class MessageParser : public QObject
{
    Q_OBJECT
public:
    explicit MessageParser(QObject *parent = nullptr);

    static ServerResult parseServerResponse(const QByteArray &data);

signals:

private:
    static ReturnInfo parserServerData(QJsonObject &jsonData, int type);
};

#endif // MESSAGEPARSER_H
