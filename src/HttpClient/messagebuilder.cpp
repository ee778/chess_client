#include "messagebuilder.h"
#include <QJsonObject>
#include <QJsonDocument>
MessageBuilder::MessageBuilder(QObject *parent)
    : QObject{parent}
{}

QByteArray MessageBuilder::buildUserRegistrationMessage(const QString &userName, const QString &password)
{
    QByteArray message;

    // 受用QJsonDocument构建JSON消息
    QJsonObject jsonObject;
    jsonObject["type"] = "1000";
    jsonObject["username"] = userName;
    jsonObject["password"] = password;
    QJsonDocument jsonDoc(jsonObject);
    message = jsonDoc.toJson(QJsonDocument::Compact);
    return message;
}
