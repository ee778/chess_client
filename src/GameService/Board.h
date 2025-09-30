#ifndef BOARD_H
#define BOARD_H

#include "GameService_global.h"
#include "Stone.h"
#include <vector>

// Board 类只存储状态，不进行逻辑判断
class Board
{
public:
    Board(int size = 19);  // 默认19 * 19棋盘

    /**
     * @brief placeStone // 落子
     * @param x
     * @param y
     * @param color
     * @return
     */
    bool placeStone(int x, int y, Color color);

    /**
     * @brief clearStone 清空所有棋子
     */
    void clearStone();

    /**
     * @brief getGrid 获取棋盘
     * @return 返回棋盘的副本
     */
    std::vector<std::vector<Stone>> getGrid();

private:

    std::vector<std::vector<Stone>> grid; // 棋盘  使用vector<Stone> 存储的对象是在堆上的
    int size;
};

#endif // BOARD_H

