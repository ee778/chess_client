#include "GameStatus.h"

GameStatus::GameStatus()
{
    clearStatus();
}

void GameStatus::clearStatus()
{
    board.clearStone();
    this->historyBoards.clear();
    this->currentColor = Color::WHITE; // 初始化时黑色为先手
    if (this->rule != nullptr)
    {
        delete this->rule;
        this->rule = nullptr;
    }


}
