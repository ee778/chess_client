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
