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
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    if (!jsonDoc.isNull() && jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        if (jsonObj.contains("code") && jsonObj["code"].isDouble())
        {
            result.code = jsonObj["code"].toInt(400);
        }
        else { // 解析失败，提前返回
            return result;
        }
        if (jsonObj.contains("message") && jsonObj["message"].isString())
        {
            result.message = jsonObj["message"].toString();
        }

        if (!jsonObj.contains("data") || !jsonObj["data"].isObject())
        {
            // 解析失败，提前返回
            return result;
        }

        QJsonObject jsonData = jsonObj["data"].toObject();
        if (jsonData.contains("type") && jsonData["type"].isDouble())
        {
            int type = jsonData["type"].toInt(0);
            result.serverData.type = type;
            ReturnInfo returnInfo = parserServerData(jsonData, type);
            if (type != 0)
            {
                result.success = returnInfo.success;
            }
            else
            {
                result.success = false;
            }
            return result;
        }
    }
    return result;
}

ReturnInfo MessageParser::parserServerData(QJsonObject &jsonData, int type)
{
    ReturnInfo returnInfo;
    switch (type)
    {
    case 1000: // 用户注册
        returnInfo.success = true;
        break;
    default:
        break;
    }
    return returnInfo;
}


