#include <ctime>
#include "Gomoku.hpp"

int main()
{
    CommandManager cmd;
    std::string input;
    std::srand(std::time(nullptr));

    while (cmd.getOutput() != "END")
    {
        std::getline(std::cin, input);
        cmd.setInput(input);
        cmd.dispatchCmd();
    }
    return 0;
}