//
// Created by romanebezier on 24/10/2019.
//

#ifndef PBRAIN_GOMOKU_AI_BOARD_HPP
#define PBRAIN_GOMOKU_AI_BOARD_HPP

#include <vector>

class Board {
public:
    Board(size_t size);
    ~Board() = default;
    Board() = default;

    void addCoordinates(const int &player, std::pair<int, int> pos);

    const std::vector<std::vector<int>> &getBoard();
    size_t getSize() const;
    bool isEmpty();
    int getCell(int, int);
    void display();

private:
    size_t _size;
    std::vector<std::vector<int>> _board;
};

#endif //PBRAIN_GOMOKU_AI_BOARD_HPP
