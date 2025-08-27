#ifndef MESSAGEPARSER_H
#define MESSAGEPARSER_H

#include <QObject>

class MessageParser : public QObject
{
    Q_OBJECT
public:
    explicit MessageParser(QObject *parent = nullptr);

signals:
};

#endif // MESSAGEPARSER_H
