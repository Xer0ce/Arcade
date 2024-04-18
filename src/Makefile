##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = arcade

CPPFLAGS = -std=c++20

all: core games graphicals

games:
	$(MAKE) -C src/game/pacman/ all
	$(MAKE) -C src/game/snake/ all
	$(MAKE) -C src/game/menu/ all

core:
	$(MAKE) -C src/core/ all

graphicals:
	$(MAKE) -C src/lib/sfml/ all
	$(MAKE) -C src/lib/sdl2/ all
	$(MAKE) -C src/lib/ncurses/ all

clean:
	$(MAKE) -C src/game/pacman/ clean
	$(MAKE) -C src/game/snake/ clean
	$(MAKE) -C src/game/menu/ clean

	$(MAKE) -C src/core/ clean

	$(MAKE) -C src/lib/sfml/ clean
	$(MAKE) -C src/lib/sdl2/ clean
	$(MAKE) -C src/lib/ncurses/ clean

fclean: clean
	$(MAKE) -C src/game/pacman/ fclean
	$(MAKE) -C src/game/snake/ fclean
	$(MAKE) -C src/game/menu/ fclean

	$(MAKE) -C src/core/ fclean

	$(MAKE) -C src/lib/sfml/ fclean
	$(MAKE) -C src/lib/sdl2/ fclean
	$(MAKE) -C src/lib/ncurses/ fclean

re: fclean all

.PHONY : all games core graphicals clean debug fclean re
