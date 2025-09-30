#include "Board.h"

Board::Board(int size)
{
    this->size = size;
    this->grid.clear();

    for (int i = 0; i < size; i++)
    {
        std::vector<Stone> tmpVector;
        for (int j = 0; j < size; j++)
        {
            Stone stone(i, j, Color::EMPTY);
            tmpVector.push_back(stone);
        }
        this->grid.push_back(tmpVector);
    }
}

bool Board::placeStone(int x, int y, Color color)
{
    // 如果超越边界，需要直接返回失败
    if (x >= size || y >= size)
    {
        return false;
    }

    // 如果不是空的，那么失败
    if (this->grid[x][y].getColor() != Color::EMPTY)
    {
        return false;
    }

    //其他规则给规则类来进行提前判断
    this->grid[x][y].setColor(color);
    return true;
}

void Board::clearStone()
{
    // 将所有的点位都变为空
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            this->grid[i][j].setColor(Color::EMPTY);
        }
    }
    return;
}

std::vector<std::vector<Stone> > Board::getGrid()
{
    return this->grid;
}
