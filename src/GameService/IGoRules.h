#ifndef IGORULES_H
#define IGORULES_H
#include "GameService_global.h"
// 围棋规则类

enum class GameResult;

class Board;
class IGoRules {
public:
    // 显式构造函数 需要棋盘类来存储状态
    explicit IGoRules(const Board* board){}

    //析构虚函数
    virtual ~IGoRules(){}

    /**
     * @brief isValidMove 检查落子是否合法
     * @param board
     * @param x
     * @param y
     * @param color
     * @return
     */
    virtual bool isValidMove(int x, int y, Color color) = 0;

    /**
     * @brief makeMove 执行落子并处理
     * @param board
     * @param x
     * @param y
     * @param color
     * @return
     */
    virtual bool makeMove(const Board& board, int x, int y, Color color) = 0;

    virtual bool isGameOver() = 0;


};

#endif // IGORULES_H
