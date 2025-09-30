#ifndef GORULESBYCHINESE_H
#define GORULESBYCHINESE_H
#include "IGoRules.h"
class Board;
class GoRulesByChinese: public IGoRules
{
public:
    GoRulesByChinese();

    ~GoRulesByChinese();

    /**
     * @brief isValidMove 检查落子是否合法
     * @param board
     * @param x
     * @param y
     * @param color
     * @return
     */
    bool isValidMove(const Board& board, int x, int y, Color color);

    /**
     * @brief makeMove 执行落子并处理
     * @param board
     * @param x
     * @param y
     * @param color
     * @return
     */
    bool makeMove(const Board& board, int x, int y, Color color);
};

#endif // GORULESBYCHINESE_H
