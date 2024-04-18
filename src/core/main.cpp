/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main
*/

 #include "Arcade.hpp"

 int main(int ac, char **av)
 {
    if (ac != 2) {
        std::cerr << "Usage: ./arcade libname" << std::endl;
        return 84;
    }

    Core::Arcade arcade(av[1]);

    if (!arcade.start())
        return 84;
    return 0;

 }
