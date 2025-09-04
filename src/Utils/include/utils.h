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

    static ResultCodeType ResultCodeTypeConvertFromInt(int code);

    static bool ResultCodeTypeIsSuccess(ResultCodeType code) {
        return code == ResultCodeType::OK || code == ResultCodeType::CREATESUCESS;
    }
};

#endif // UTILS_H
