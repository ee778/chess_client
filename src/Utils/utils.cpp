#include "utils.h"

Utils::Utils() {}

MessageType Utils::MessageTypeConvertFromInt(int Type)
{
    switch (Type)
    {
    case 1000:
        return MessageType::REGISTER;
    case 1001:
        return MessageType::LOGIN;
    default:
        return MessageType::FAILED;
    }
}

ResultCodeType Utils::ResultCodeTypeConvertFromInt(int code)
{
    switch (code)
    {
    case 200:
        return ResultCodeType::OK;
    case 201:
        return ResultCodeType::CREATESUCESS;
    case 400:
        return ResultCodeType::BADREQUEST;
    case 401:
        return ResultCodeType::UNAUTHORIZED;
    default:
        return ResultCodeType::BADREQUEST;
    }
}
