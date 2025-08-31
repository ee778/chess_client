#ifndef APPSTARTUP_H
#define APPSTARTUP_H

#include <QObject>

class AppStartup
{
public:
    // 单例模式
    static AppStartup* getInstance()
    {
        static AppStartup appStartup;
        return &appStartup;
    }
    // 禁用拷贝构造函数和赋值运算符
    AppStartup(const AppStartup&) = delete;
    AppStartup& operator=(const AppStartup&) = delete;

    // 开始服务
    bool startup();

private:
    AppStartup();
};

#endif // APPSTARTUP_H
