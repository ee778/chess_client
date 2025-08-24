#ifndef CCONFIG_H
#define CCONFIG_H

#include <QObject>
#include <QSettings>
class CConfig: public QObject
{
public:
    CConfig* getInstance();


    // 设置配置值
    void setValue(const QString &key, const QVariant &value);

    QVariant getValue(const QString &key, const QVariant &defaultValue = QVariant()) const;

    bool contains(const QString &key) const;

    void sync();
private:
    explicit CConfig(QString fileName, QSettings::Format format, QObject *parent = nullptr);
    ~CConfig();
    QSettings* m_settings;
};

#endif // CCONFIG_H
