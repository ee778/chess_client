#ifndef STONE_H
#define STONE_H
#include "GameService_global.h"

class Stone
{
public:
    /**
     * @brief Stone 显式棋子构造函数
     * @param x
     * @param y
     * @param color
     */
    explicit Stone(int x, int y, Color color);

    bool setPosition(int x, int y);
    bool setColor(Color color);

    Color getColor();
    std::pair<int, int> getPosition();
private:
    int x;
    int y;
    Color color;
};

#endif // STONE_H
