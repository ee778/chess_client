#include "cconfig.h"
#include <QDir>


CConfig *CConfig::getInstance()
{
    static CConfig config(QDir::currentPath() + "config.ini", QSettings::Format::IniFormat, nullptr);

    return &config;
}

void CConfig::setValue(const QString &key, const QVariant &value)
{
    m_settings->setValue(key, value);
}

QVariant CConfig::getValue(const QString &key, const QVariant &defaultValue) const
{
    return m_settings->value(key, defaultValue);
}

bool CConfig::contains(const QString &key) const
{
    return m_settings->contains(key);
}

void CConfig::sync()
{
    m_settings->sync();
}

CConfig::CConfig(QString fileName, QSettings::Format format, QObject *parent)
    :QObject(parent)
{

}

CConfig::~CConfig()
{

}



