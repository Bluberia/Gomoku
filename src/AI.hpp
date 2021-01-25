//
// Created by romanebezier on 24/10/2019.
//

#include "Tree.hpp"
#include "Board.hpp"

#ifndef AIA_GOMOKU_2019_AI_HPP
#define AIA_GOMOKU_2019_AI_HPP

class AI {
public:
    AI();
    ~AI();

    /** minimax
     * @param Node : current position in possibility tree
     * @param depth : depth to search 
     * @param isMaximizingPlayer : player turn 
     * find the best next move for the ai to play
     */

    std::pair<int, std::pair<int,int>> minimax(std::shared_ptr<Node> node, int depth, bool isMaximizingPlayer);

    /** evalNode
     * @param pos
     * @param board
     * @param player
     * evaluate the value of the move
     */
    int evalNode(std::pair<int,int> pos, Board board, int player);

    /** generatePossibilityTree
     * @param Board : current game state
     * @param depth : number of turn to generate 
     * @param Node : root of the tree
     * @param bool : player in play
     */
    void generatePossibilityTree(Board _board, int depth, const std::shared_ptr<Node> &node, bool player);

    /** resetVal
     * reset the value of current bestval
     *
     */
    std::pair<int, int> evalVertical(const std::pair<int, int>&, Board board, int player);
    /** evalHorizontal
     *
     */
    std::pair<int, int> evalHorizontal(const std::pair<int, int>&, Board board, int player);
    /** evalFirstDiagonals
     *
     */
    std::pair<int, int> evalFirstDiagonals(const std::pair<int, int>&, Board board, int player);
    /** evalFirstDiagonals
     *
     */
    std::pair<int, int> evalSecondDiagonals(const std::pair<int, int>&, Board board, int player);

    /** hasAdjacent
     *
     */
    bool hasAdjacent(Board, int, int);

private:

    /** firstChange
     *
     * @param maxPlayer
     * @param next
     * @param res
     * @param player
     */
    void firstChange(bool &maxPlayer, int next, std::pair<int,int> &res, int player);
    /** secondChange
     *
     * @param maxPlayer
     * @param next
     * @param res
     * @param player
     */
    void secondChange(bool &maxPlayer, int next, std::pair<int,int> &res, int player);
    /** checkExtremityVert
     * @param pos
     * @param res
     * @param player
     * @param board
     */
    void checkExtremityVert(const std::pair<int, int> &pos, std::pair<int,int> &res, int player, Board board);
    /** checkExtremityHori
     *
     * @param pos
     * @param res
     * @param player
     * @param board
     */
    void checkExtremityHori(const std::pair<int, int> &pos, std::pair<int,int> &res, int player, Board board);
    /** checkExtremityFirstDiag
    *
    */
    void checkExtremityFirstDiag(const std::pair<int, int> &pos, std::pair<int,int> &res, int player, Board board);
    /** checkExtremitySecondDiag
    *
    */
    void checkExtremitySecondDiag(const std::pair<int, int> &pos, std::pair<int,int> &res, int player, Board board);
    /** evalVictory
    *
    */
    int evalVictory(const std::pair<int, int> &pos, Board board, int player);
    /** checlVictory
    *
    */
    int checkVictory(const std::pair<int, int> &pos, Board board, int player);
};

#endif //AIA_GOMOKU_2019_AI_HPP
