##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = arcade

SRC = ./main.cpp \
	  ./Arcade.cpp \
	  ./DLopener.cpp \

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -std=c++20 -g3

NCURSESFLAG = -lncurses

SFMLFLAG = -lsfml-graphics -lsfml-window -lsfml-system

SDLFLAG = -lSDL2 -lSDL2_image -lSDL2_ttf

$(NAME): $(OBJ)
	g++ $(OBJ) -o $(NAME) $(CPPFLAGS)

all: $(NAME)
	mv $(NAME) ../../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../$(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: $(OBJ)
	@g++ -o $(NAME) $(OBJ) -g3

.PHONY : all clean debug fclean re
