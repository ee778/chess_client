#ifndef HTTPSERVICE_H
#define HTTPSERVICE_H
#include <QObject>
#include "IHttpClient.h"
#include "global.h"
class HttpService: public QObject
{
    Q_OBJECT
public:

    // 单例模式
    static HttpService* getInstance(IHttpClient *client = nullptr)
    {
        static HttpService httpService(client);
        return &httpService;
    }
    // delete拷贝构造函数和赋值运算符
    HttpService(const HttpService&) = delete;
    HttpService& operator=(const HttpService&) = delete;
    bool setHttpClient(IHttpClient *client);
    ~HttpService();

    /**
     * @brief registerUser 注册用户
     * @param userName  用户名
     * @param password  密码
     * @param async 是否异步
     */
    void registerUser(const QString &userName, const QString &password, bool async = false);

    /**
     * @brief loginUser 用户登录
     * @param userName 用户名
     * @param password 密码
     * @param async 是否异步
     */
    void loginUser(const QString &userName, const QString &password, bool async = false);

    void logoutUser() {
        // 目前不需要做任何操作
    }
private:
    HttpService(IHttpClient *client, QObject *parent = nullptr);
private slots:
    void processError(const QString &err);
    void processFinished(const QByteArray &data);
signals:
    void registerFinished(ServerResult result);

    void loginFinished(ServerResult result);
private:
    IHttpClient *m_client;
};

#endif // HTTPSERVICE_H
