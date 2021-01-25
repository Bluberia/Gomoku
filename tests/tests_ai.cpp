//
// Created by romanebezier on 27/10/2019.
//

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <utility>
#include "../src/AI.hpp"

Test(ai, evalVertical)
{
    AI ai = AI();
    Board board = Board(15);

    std::pair<int,int> res = ai.evalVertical(std::make_pair(3, 1), board, 1);
    cr_assert_eq(res, std::make_pair(12,12));
    board.addCoordinates(1, std::make_pair(2,1));
    res = ai.evalVertical(std::make_pair(1, 1), board, 1);
    cr_assert_eq(res, std::make_pair(22,11));
}

Test(ai, evalHorizontal)
{
    AI ai = AI();
    Board board = Board(15);

    std::pair<int,int> res = ai.evalHorizontal(std::make_pair(3, 1), board, 1);
    cr_assert_eq(res, std::make_pair(12,12));
    board.addCoordinates(1, std::make_pair(2,1));
    res = ai.evalHorizontal(std::make_pair(2,2), board, 1);
    cr_assert_eq(res, std::make_pair(22,11));
}

Test(ai, evalFirstDiagonals)
{
    AI ai = AI();
    Board board = Board(15);

    std::pair<int,int> res = ai.evalFirstDiagonals(std::make_pair(3, 1), board, 1);
    cr_assert_eq(res, std::make_pair(12,12));

    board.addCoordinates(1, std::make_pair(2,1));
    res = ai.evalFirstDiagonals(std::make_pair(3, 2), board, 1);
    cr_assert_eq(res, std::make_pair(22,11));
}

Test(ai, evalSecondDiagonals)
{
    AI ai = AI();
    Board board = Board(15);

    std::pair<int,int> res = ai.evalSecondDiagonals(std::make_pair(3, 1), board, 1);
    cr_assert_eq(res, std::make_pair(12,12));

    board.addCoordinates(1, std::make_pair(13,2));
    res = ai.evalSecondDiagonals(std::make_pair(14, 1), board, 1);
    cr_assert_eq(res, std::make_pair(21,10));
}

Test(ai, hasAdjacent)
{
    AI ai = AI();
    Board board = Board(12);

    cr_assert_eq(ai.hasAdjacent(board, 1, 1), false);
    board.addCoordinates(1, std::make_pair(0,1));
    cr_assert_eq(ai.hasAdjacent(board, 1, 1), true);

}
