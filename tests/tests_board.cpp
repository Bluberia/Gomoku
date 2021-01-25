//
// Created by romanebezier on 27/10/2019.
//

#include <criterion/criterion.h>
#include "../src/Board.hpp"

Test(Board, createBoard) {
    Board board = Board(20);

    for (int i = 0; i < 20; i++)
        for (int y = 0; y < 20; y++)
            cr_assert_eq(board.getCell(i, y), 0);
}

Test(Board, addCoordinates) {
    Board board = Board(3);

    board.addCoordinates(2, std::make_pair(1, 0));
    cr_assert_eq(board.getCell(1, 0), 2);
}

Test(Board, getSize) {
    Board board = Board(3);

    cr_assert_eq(board.getSize(), 2);
}

Test(Board, isEmpty) {
    Board board = Board(3);

    cr_assert_eq(board.isEmpty(), true);

    board.addCoordinates(2, std::make_pair(1, 0));
    cr_assert_eq(board.isEmpty(), false);
}

Test(Board, getBoard) {
    Board board = Board(3);

    const std::vector<std::vector<int>> &res = board.getBoard();
    for (int i = 0; i < board.getSize(); i++)
        for (int y = 0; y < board.getSize(); y++)
            cr_assert_eq(res[i][y], 0);
}