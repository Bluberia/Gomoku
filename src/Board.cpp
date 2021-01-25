//
// Created by romanebezier on 24/10/2019.
//

#include <iostream>
#include <string>
#include "Board.hpp"

Board::Board(size_t size) : _size(size - 1) {
    _board.resize(size);
    for (size_t i = 0; i < size; i++) {
        _board[i].resize(size);
        _board[i].shrink_to_fit();
    }
    _board.shrink_to_fit();
    for(size_t i = 0; i < size; i++)
        for (size_t y = 0; y < size; y++)
            _board[i][y] = 0;
}

void Board::addCoordinates(const int &player, std::pair<int, int> pos) {
    _board[pos.first][pos.second] = player;
}

const std::vector<std::vector<int>> &Board::getBoard() {
    return _board;
}

size_t Board::getSize() const {
    return _size;
}

bool Board::isEmpty() {
    for(size_t i = 0; i < _size; i++)
        for (size_t y = 0; y < _size; y++)
            if (_board[i][y] != 0)
                return false;
    return true;
}

int Board::getCell(int x, int y) {
    if (x < 0 || y < 0 || x > static_cast<int>(getSize()) || y > static_cast<int>(getSize()))
        return -1;
    return getBoard()[x][y];
}

void Board::display() {
    for (size_t i = 0; i <= _size; i++) {
        for (size_t y = 0; y <= _size; y++)
            std::cout << std::to_string(_board[i][y]);
        std::cout << std::endl;
    }
}