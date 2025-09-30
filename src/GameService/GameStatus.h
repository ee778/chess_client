#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include "GameService_global.h"
#include "Board.h"

#include <vector>
class IGoRules;
class GameStatus
{
public:
    GameStatus();

    bool playMove(int x, int y);

    // 悔棋--回到上一个棋盘--更新当前角色
    bool undo();

    Color getCurrentPlayer();

    // 获取当前的棋盘状态
    const Board &getBoard() const;

    // 获取游戏结果
    GameResult getResult() const;

    // 清空所有状态
    void clearStatus();

private:
    Board board;  // 当前的棋盘状态
    IGoRules *rule = nullptr;
    Color currentColor;

    std::vector<Board> historyBoards;   // 历史棋盘记录
};

#endif // GAMESTATUS_H
