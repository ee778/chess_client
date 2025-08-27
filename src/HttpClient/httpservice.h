#ifndef HTTPSERVICE_H
#define HTTPSERVICE_H
#include <QObject>
#include "IHttpClient.h"

const QString URL = "127.0.0.1:8080";  // 后期写在配置文件中

struct ServerData {
    int type;   // 数据的类型
    void* data; // 数据指针
};

struct ServerResult {
    bool success = false;  // 请求解析成功
    int code;  // 业务状态码
    QString message;  // 本次返回的信息
    ServerData data;  // 具体数据
};

class HttpService: public QObject
{
    Q_OBJECT
public:
    HttpService(IHttpClient *client, QObject *parent = nullptr);
    ~HttpService();

    /**
     * @brief registerUser 注册用户
     * @param userName  用户名
     * @param password  密码
     * @param async 是否异步
     */
    void registerUser(QString &userName, QString &password, bool async = false);
private slots:
    void processError(const QString &err);
    void processFinished(const QByteArray &data);
private:
    IHttpClient *m_client;
};

#endif // HTTPSERVICE_H
