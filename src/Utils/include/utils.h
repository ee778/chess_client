#ifndef UTILS_H
#define UTILS_H
#include "global.h"
class Utils
{
public:
    Utils();

    /**
     * @brief MessageTypeConvertFromInt 将int转换为MessageType数据类型
     * @param Type int信息
     * @return
     */
    static MessageType MessageTypeConvertFromInt(int Type);
};

#endif // UTILS_H
