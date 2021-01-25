//
// Created by romanebezier on 27/10/2019.
//

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/Gomoku.hpp"

void redirectAllStd(void) {
    cr_redirect_stdout();
};

Test(CommandManager, getBoardSize) {
    CommandManager manager = CommandManager();

    cr_assert_eq(manager.getBoardSize("4"), 4);
}

Test(CommandManager, input) {
    CommandManager manager = CommandManager();

    manager.setInput("oui");
    cr_assert_eq(manager.getInput(), "oui");
}

Test(CommandManager, output) {
    CommandManager manager = CommandManager();

    manager.setOutput("oui");
    cr_assert_eq(manager.getOutput(), "oui");
}

Test(CommandManager, start, .init=redirectAllStd) {
    CommandManager manager = CommandManager();

    manager.start("10");
    cr_assert_eq(manager.getBoardSize("10"), 10);
    cr_assert_stdout_eq_str("OK\n");
}