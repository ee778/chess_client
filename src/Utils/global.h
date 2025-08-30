#ifndef GLOBAL_H
#define GLOBAL_H

class QJsonObject;
struct IData
{
    virtual int fromJson(QJsonObject jsonData) = 0;
};



struct ReturnInfo
{
    IData *data;  // 返回的数据
    bool success = false;  // 请求解析成功
};

#endif // GLOBAL_H
