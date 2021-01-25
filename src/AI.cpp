//
// Created by romanebezier on 24/10/2019.
//

#include <limits>
#include <memory>
#include "AI.hpp"
#include <iostream>

AI::AI() {
}

AI::~AI() {
}

std::pair<int, std::pair<int,int>> AI::minimax(std::shared_ptr<Node> node, int depth, bool isMaximizingPlayer)
{
    std::pair<int, std::pair<int,int>> res;
    std::pair<int, std::pair<int,int>> tmp;

    if (depth == 0 || node->getChildren().empty()) {
        return std::make_pair(node->getValue(), node->getPos());
    }
    if (isMaximizingPlayer) {
        res.first = std::numeric_limits<int>::min();
        for (const auto &it : node->getChildren()) {
            tmp = minimax(it, depth - 1, !isMaximizingPlayer);
            if (tmp.first > res.first) {
                res.first = tmp.first;
                res.second = it->getPos();
            }
        }
    } else {
        res.first  = std::numeric_limits<int>::max();
        for (const auto &it : node->getChildren()) {
            tmp = minimax(it, depth - 1, !isMaximizingPlayer);
            if (tmp.first < res.first) {
                res.first = tmp.first;
                res.second = it->getPos();
            }
        }
    }
    return res;
}

void AI::firstChange(bool &maxPlayer, int next, std::pair<int,int> &res, int player)
{
    if (maxPlayer && next == player)
        res.first += 10;
    else
        maxPlayer = false;
}

void AI::secondChange(bool &maxPlayer, int next, std::pair<int,int> &res, int player)
{
    int enemy = 2;
    if (player == 2)
        enemy = 1;

    if (!maxPlayer && next == enemy)
        res.second += 10;
    else
        maxPlayer = true;
}

void AI::checkExtremityVert(const std::pair<int, int> &pos, std::pair<int,int> &res, int player, Board board)
{
    int next = 0;
    int enemy = 2;
    if (player == 2)
        enemy = 1;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second);
        if (next == enemy)
            break;
        else if (next == 0) {
            res.first++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second);
        if (next == enemy)
            break;
        else if (next == 0) {
            res.first++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second);
        if (next == player)
            break;
        else if (next == 0) {
            res.second++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second);
        if (next == player)
            break;
        else if (next == 0) {
            res.second++;
            break;
        }
    }
}

std::pair<int,int> AI::evalVertical(const std::pair<int, int> &pos, Board board, int player)
{
    std::pair<int,int> res = {10,10};
    bool maxPlayer = true;
    int next = 0;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second);
        firstChange(maxPlayer, next, res, player);
    }
    maxPlayer = true;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second);
        firstChange(maxPlayer, next, res, player);
    }
    maxPlayer = false;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second);
        secondChange(maxPlayer, next, res, player);
    }
    maxPlayer = false;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second);
        secondChange(maxPlayer, next, res, player);
    }
    checkExtremityVert(pos, res, player, board);
    return res;
}

void AI::checkExtremityHori(const std::pair<int, int> &pos, std::pair<int,int> &res, int player, Board board)
{
    int next = 0;
    int enemy = 2;
    if (player == 2)
        enemy = 1;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first, pos.second + i);
        if (next == enemy)
            break;
        else if (next == 0) {
            res.first++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first, pos.second - i);
        if (next == enemy)
            break;
        else if (next == 0) {
            res.first++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first, pos.second + i);
        if (next == player)
            break;
        else if (next == 0) {
            res.second++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first, pos.second - i);
        if (next == player)
            break;
        else if (next == 0) {
            res.second++;
            break;
        }
    }
}

std::pair<int, int> AI::evalHorizontal(const std::pair<int, int> &pos, Board board, int player)
{
    std::pair<int,int> res = {10,10};
    bool maxPlayer = true;
    int next = 0;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first, pos.second + i);
        firstChange(maxPlayer, next, res, player);
    }
    maxPlayer = true;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first, pos.second - i);
        firstChange(maxPlayer, next, res, player);
    }
    maxPlayer = false;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first, pos.second + i);
        secondChange(maxPlayer, next, res, player);
    }
    maxPlayer = false;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first, pos.second - i);
        secondChange(maxPlayer, next, res, player);
    }
    checkExtremityHori(pos, res, player, board);
    return res;
}

void AI::checkExtremityFirstDiag(const std::pair<int, int> &pos, std::pair<int,int> &res, int player, Board board)
{
    int next = 0;
    int enemy = 2;
    if (player == 2)
        enemy = 1;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second + i);
        if (next == enemy)
            break;
        else if (next == 0) {
            res.first++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second - i);
        if (next == enemy)
            break;
        else if (next == 0) {
            res.first++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second + i);
        if (next == player)
            break;
        else if (next == 0) {
            res.second++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second - i);
        if (next == player)
            break;
        else if (next == 0) {
            res.second++;
            break;
        }
    }
}

std::pair<int, int> AI::evalFirstDiagonals(const std::pair<int, int> &pos, Board board, int player)
{
    std::pair<int,int> res = {10,10};
    bool maxPlayer = true;
    int next = 0;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second + i);
        firstChange(maxPlayer, next, res, player);
    }
    maxPlayer = true;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second - i);
        firstChange(maxPlayer, next, res, player);
    }
    maxPlayer = false;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second + i);
        secondChange(maxPlayer, next, res, player);
    }
    maxPlayer = false;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second - i);
        secondChange(maxPlayer, next, res, player);
    }
    checkExtremityFirstDiag(pos, res, player, board);
    return res;
}

void AI::checkExtremitySecondDiag(const std::pair<int, int> &pos, std::pair<int,int> &res, int player, Board board)
{
    int next = 0;
    int enemy = 2;
    if (player == 2)
        enemy = 1;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second - i);
        if (next == enemy)
            break;
        else if (next == 0) {
            res.first++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second + i);
        if (next == enemy)
            break;
        else if (next == 0) {
            res.first++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second - i);
        if (next == player)
            break;
        else if (next == 0) {
            res.second++;
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second + i);
        if (next == player)
            break;
        else if (next == 0) {
            res.second++;
            break;
        }
    }
}

std::pair<int, int> AI::evalSecondDiagonals(const std::pair<int, int> &pos, Board board, int player)
{
    std::pair<int,int> res = {10,10};
    bool maxPlayer = true;
    int next = 0;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second - i);
        firstChange(maxPlayer, next, res, player);
    }
    maxPlayer = true;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second + i);
        firstChange(maxPlayer, next, res, player);
    }
    maxPlayer = false;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second - i);
        secondChange(maxPlayer, next, res, player);
    }
    maxPlayer = false;
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second + i);
        secondChange(maxPlayer, next, res, player);
    }
    checkExtremitySecondDiag(pos, res, player, board);
    return res;
}

int AI::evalVictory(const std::pair<int, int> &pos, Board board, int player) {
    int victory = 0;
    int next = 0;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second);
        if (next == player)
            victory++;
        else
            break;
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second);
        if (next == player)
            victory++;
        else
            break;
    }
    if (victory >= 4)
        return 1;
    victory = 0;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first, pos.second + i);
        if (next == player)
            victory++;
        else
            break;
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first, pos.second - i);
        if (next == player)
            victory++;
        else
            break;
    }
    if (victory >= 4)
        return 1;
    victory = 0;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second + i);
        if (next == player)
            victory++;
        else
            break;
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second - i);
        if (next == player)
            victory++;
        else
            break;
    }
    if (victory >= 4)
        return 1;
    victory = 0;

    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first + i, pos.second - i);
        if (next == player)
            victory++;
        else
            break;
    }
    for (int i = 1; i <= 4; i++) {
        next = board.getCell(pos.first - i, pos.second + i);
        if (next == player)
            victory++;
        else
            break;
    }
    if (victory >= 4)
        return 1;
    return 0;
}

int AI::checkVictory(const std::pair<int, int> &pos, Board board, int player)
{
    int enemy = 2;
    if (player == 2)
        enemy = 1;
    int victoryAI = evalVictory(pos, board, player);
    int victoryEnemy = evalVictory(pos, board, enemy);

    if (victoryAI == 1)
        return -2;
    else if (victoryEnemy == 1)
        return -1;
    return 0;
}

int AI::evalNode(std::pair<int, int> pos, Board board, int player)
{
    int resVictory = checkVictory(pos, board, player);
    if (resVictory != 0) {
        if (resVictory == -1)
            return std::numeric_limits<int>::max() - 1;
        else
            return std::numeric_limits<int>::max();
    }
    std::pair<int, int> verticalValue = evalVertical(pos, board, player);
    std::pair<int, int> horizontalValue = evalHorizontal(pos, board, player);
    std::pair<int, int> firstDiagonalsValue = evalFirstDiagonals(pos, board, player);
    std::pair<int, int> secondDiagonalsValue = evalSecondDiagonals(pos, board, player);
    std::pair<int, int> res = {verticalValue.first, verticalValue.second};

    if (res.first < horizontalValue.first)
        res.first = horizontalValue.first;
    if (res.first < firstDiagonalsValue.first)
        res.first = firstDiagonalsValue.first;
    if (res.first < secondDiagonalsValue.first)
        res.first = secondDiagonalsValue.first;
    if (res.second < horizontalValue.second)
        res.second = horizontalValue.second;
    if (res.second < firstDiagonalsValue.second)
        res.second = firstDiagonalsValue.second;
    if (res.second < secondDiagonalsValue.second)
        res.second = secondDiagonalsValue.second;

    if (res.first > res.second)
        return res.first;
    else
        return res.second;
}

bool AI::hasAdjacent(Board board, int x, int y)
{
    return board.getCell(x + 1, y) > 0 ||
           board.getCell(x, y + 1) > 0 ||
           board.getCell(x - 1, y) > 0 ||
           board.getCell(x, y - 1) > 0 ||
           board.getCell(x + 1, y + 1) > 0 ||
           board.getCell(x + 1, y - 1) > 0 ||
           board.getCell(x - 1, y + 1) > 0 ||
           board.getCell(x - 1, y - 1) > 0;
}

void AI::generatePossibilityTree(Board board, int depth, const std::shared_ptr<Node> &node, bool player)
{
    if (depth == 0)
        return;
    node->setBoard(board);
    if (board.isEmpty()) {
        for (size_t i = 0; i <= board.getSize(); i++)
            for (size_t j = 0; j <= board.getSize(); j++)
                node->setChild(std::make_shared<Node>(0, std::make_pair(i, j)));
        return;
    }
    for (size_t i = 0; i <= board.getSize(); i++) {
        for (size_t j = 0; j <= board.getSize(); j++) {
            if (board.getCell(i, j) == 0 && hasAdjacent(board, i, j)) {
                Board tmpBoard = board;
                tmpBoard.addCoordinates((player ? 1 : 2), std::make_pair(i, j));
                node->setChild(std::make_shared<Node>(evalNode(std::make_pair(i, j), tmpBoard, (player ? 1 : 2)), std::make_pair(i, j), tmpBoard));
                generatePossibilityTree(tmpBoard, depth - 1, node->getChildren().back(), !player);
            }
        }
    }
}