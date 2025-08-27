#include "messageparser.h"
#include "httpservice.h"
#include <QJsonObject>
#include <QJsonDocument>
MessageParser::MessageParser(QObject *parent)
    : QObject{parent}
{}

ServerResult MessageParser::parseServerResponse(const QByteArray &data)
{
    ServerResult result;
    // 解析data，填充result

    return result;
}
