#ifndef MESSAGEBUILDER_H
#define MESSAGEBUILDER_H

#include <QObject>

// 消息构造器类
class MessageBuilder : public QObject
{
    Q_OBJECT
public:
    explicit MessageBuilder(QObject *parent = nullptr);

    static QByteArray buildUserRegistrationMessage(const QString &userName, const QString &password);

    /**
     * @brief buildUserLoginMessage 构建用户登录消息
     *  
     * @param userName  用户名
     * @param password  密码
     * @return QByteArray 
     */
    static QByteArray buildUserLoginMessage(const QString &userName, const QString &password);
    /**
     * @brief buildResponseErrorMessage 创建错误响应消息
     * @param error 错误信息
     * @return 构建好的消息
     */
    static QByteArray buildResponseErrorMessage(const QString &error);
signals:
};

#endif // MESSAGEBUILDER_H
