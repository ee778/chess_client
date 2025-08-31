#include "messagebuilder.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "global.h"
MessageBuilder::MessageBuilder(QObject *parent)
    : QObject{parent}
{}

QByteArray MessageBuilder::buildUserRegistrationMessage(const QString &userName, const QString &password)
{
    QByteArray message;

    // 受用QJsonDocument构建JSON消息
    QJsonObject jsonObject;
    jsonObject["type"] = 1000;
    jsonObject["username"] = userName;
    jsonObject["password"] = password;
    QJsonDocument jsonDoc(jsonObject);
    message = jsonDoc.toJson(QJsonDocument::Compact);
    return message;
}

QByteArray MessageBuilder::buildResponseErrorMessage(const QString &error)
{
    QByteArray message;
    QJsonObject jsonObject;
    QJsonObject jsonData;
    jsonObject["code"] = 400; // 假设4000表示错误响应
    jsonObject["message"] = error;
    jsonData["type"] = static_cast<int>(MessageType::FAILED);
    jsonObject["data"] = jsonData;

    QJsonDocument jsonDoc(jsonObject);
    message = jsonDoc.toJson(QJsonDocument::Compact);
    return message;
}

