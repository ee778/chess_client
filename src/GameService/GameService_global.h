#ifndef GAMESERVICE_GLOBAL_H
#define GAMESERVICE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GAMESERVICE_LIBRARY)
#define GAMESERVICE_EXPORT Q_DECL_EXPORT
#else
#define GAMESERVICE_EXPORT Q_DECL_IMPORT
#endif

enum class Color
{
    EMPTY,
    BLACK,
    WHITE,
};
enum class GameResult{
    NOT_OVER,
    BLACK_WIN,
    WHITE_WIN,
    DRAW, // 平局的含义
};

#endif // GAMESERVICE_GLOBAL_H
