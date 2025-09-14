#include "global.h"
#include <QJsonObject>
int LoginData::fromJson(QJsonObject jsonData)
{
    if (jsonData.contains("token") && jsonData["token"].isString())
    {
        token = jsonData["token"].toString();
        return 0;
    }
    return -1;
}