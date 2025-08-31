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
     * @brief buildResponseErrorMessage 创建错误响应消息
     * @param error 错误信息
     * @return 构建好的消息
     */
    static QByteArray buildResponseErrorMessage(const QString &error);
signals:
};

#endif // MESSAGEBUILDER_H
