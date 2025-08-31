#include "appstartup.h"
#include "httpservice.h"
#include "httpclient.h"

bool AppStartup::startup()
{
    // 初始化HTTP客户端
    IHttpClient *client = new HttpClient();
    HttpService::getInstance(client);

    return true;
}

AppStartup::AppStartup() {}

