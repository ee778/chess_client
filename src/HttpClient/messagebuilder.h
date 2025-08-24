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
signals:
};

#endif // MESSAGEBUILDER_H
