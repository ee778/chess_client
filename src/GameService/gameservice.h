#ifndef GAMESERVICE_H
#define GAMESERVICE_H

#include "GameService_global.h"
#include "GameStatus.h"

class GAMESERVICE_EXPORT GameService
{
public:
    GameService();

    void startGame();

    void quitGame();

    // 设置当前落子的颜色（角色）
    void setCurrentColor(Color color);

    const GameResult getGameResult() const;

private:
    GameStatus gameStatus;
};

#endif // GAMESERVICE_H
