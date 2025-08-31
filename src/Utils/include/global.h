#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>

class QJsonObject;
#include <QMetaType>
struct IData
{
    virtual int fromJson(QJsonObject jsonData) = 0;
};


struct ReturnInfo
{
    IData *data;  // 返回的数据
    bool success = false;  // 请求解析成功
};

enum class MessageType {
    FAILED = 0,
    REGISTER = 1000,
    LOGIN = 1001,
};

const QString URL = "http://127.0.0.1:9191";  // 后期写在配置文件中

struct ServerData {
    MessageType type = MessageType::FAILED;   // 数据的类型
    IData* data = nullptr; // 数据指针
};

struct ServerResult {
    bool success = false;  // 请求解析成功
    int code;  // 业务状态码
    QString message;  // 本次返回的信息
    ServerData serverData;  // 具体数据
};
Q_DECLARE_METATYPE(ServerResult)
#endif // GLOBAL_H
