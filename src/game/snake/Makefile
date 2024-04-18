##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = arcade_snake.so

SRC = ../AGame.cpp \
	  ./Snake.cpp \

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -std=c++20 -fPIC -g3

NCURSESFLAG = -lncurses

SFMLFLAG = -lsfml-graphics -lsfml-window -lsfml-system

SDLFLAG = -lSDL2 -lSDL2_image -lSDL2_ttf

$(NAME): $(OBJ)
	g++ -shared -o $(NAME) $(OBJ) $(CPPFLAGS) $(NCURSESFLAG) $(SFMLFLAG) $(SDLFLAG)

all: $(NAME)
	mv $(NAME) ../../../lib/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../../lib/$(NAME)

re: fclean all


debug: CFLAGS += -g3
debug: $(OBJ)
	@g++ -o $(NAME) $(OBJ) -g3

.PHONY : all clean debug fclean re
