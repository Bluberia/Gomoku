#include "Gomoku.hpp"
#include <map>
#include <exception>
#include <ctime>
#include <utility>
#include <random>

CommandManager::CommandManager() {

}

int CommandManager::getBoardSize(const std::string& data)
{
    if (data.find_first_of("0123456789") == std::string::npos)
        return 0;
    return std::stoi(data.substr(data.find_first_of("0123456789"), data.find_last_of("0123456789") - data.find_first_of("0123456789") + 1));
}

void CommandManager::setCoordinateBoard(const std::string& data)
{
    std::string d = data;
    int x = std::stoi(d.substr(0, d.find_first_of(",")));
    d = d.substr(d.find_first_of(",") + 1);
    int y = std::stoi(d.substr(0, d.find_first_of(",")));
    d = d.substr(d.find_first_of(",") + 1);
    int player = std::stoi(d);
    std::pair<int, int> pos = std::make_pair(x, y);
    _board.addCoordinates(player, pos);
}

void CommandManager::setCoordinate(const std::string& data)
{
    if (data.find_first_of(',') == std::string::npos || data.find_first_of("0123456789") == std::string::npos)
        throw "not a coordinate";
    if (data.find_first_of("0123456789", data.find_first_of(',')) == std::string::npos)
        throw "not a coordinate";

    std::pair<int, int> pos = std::make_pair<int, int>(std::stoi(data.substr(data.find_first_of("0123456789"), data.find_last_of("0123456789") - data.find_first_of("0123456789") + 1)), std::stoi(data.substr(data.find_first_of(",") + 1, data.find_last_of("0123456789", data.find_first_of(",")) - data.find_first_of("0123456789", data.find_first_of(",")) + 1)));
    _board.addCoordinates(2, pos);
}

void CommandManager::setInput(const std::string& input)
{
    _input = input;
}

void CommandManager::setOutput(const std::string& output)
{
    _output = output;
}


std::string& CommandManager::getInput()
{
    return _input;
}

std::string& CommandManager::getOutput()
{
    return _output;
}

void CommandManager::dispatchCmd()
{
    std::map<std::string, fCmd> cmd = { {"START", &CommandManager::start}, {"BEGIN", &CommandManager::begin}, {"TURN", &CommandManager::turn}, {"BOARD", &CommandManager::board}, {"END", &CommandManager::end} };

    for (auto & i : cmd) {
        if (!_input.find(i.first, 0))
            (this->*(i.second))(_input);
    }
}

void CommandManager::start(const std::string &data)
{
    _boardSize = getBoardSize(data);
    if (_boardSize >= 5)
        answer("OK");
    else
        answer("ERROR: board too small");
    _board = Board(_boardSize);
}

void CommandManager::begin(const std::string &data)
{
    (void)data;
    Tree _tree;
    std::pair<int, std::pair<int,int>> res = {0, {0,0}};

    if (_board.isEmpty()) {
        _ai.generatePossibilityTree(_board, 1, _tree.getRoot(), true);
        int first = rand() % _boardSize;
        int second = rand() % _boardSize;
        res.first = 0;
        res.second = std::make_pair(first, second);
    } else {
        _ai.generatePossibilityTree(_board, 1, _tree.getRoot(), true);
        res = _ai.minimax(_tree.getRoot(), 1, true);
    }
    std::string response;
    response.append(std::to_string(res.second.first));
    response.append(",");
    response.append(std::to_string(res.second.second));
    _board.addCoordinates(1, res.second);
    answer(response);
}

void CommandManager::turn(const std::string &data)
{
    try {
        setCoordinate(data);
        begin(data);
    }
    catch (const char *msg) {
        std::cout << msg << std::endl;
    }
}

void CommandManager::board(const std::string &data)
{
    (void)data;
    while (_input != "DONE") {
        std::getline(std::cin, _input);
        if (_input == "DONE")
            break;
        setCoordinateBoard(_input);
    }
    begin(data);
}

void CommandManager::end(const std::string &data)
{
    setOutput(data);
}

void CommandManager::answer(const std::string& answer)
{
    std::cout << answer << std::endl;
}
