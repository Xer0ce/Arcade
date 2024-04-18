##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = arcade_sfml.so

SRC = ../ADisplay.cpp \
	  ../AEntity.cpp \
	  ./SFML.cpp \
	  ./RectangleShape.cpp \
	  ./Sprite.cpp \

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -std=c++20 -fPIC

SFMLFLAG = -lsfml-graphics -lsfml-window -lsfml-system

$(NAME): $(OBJ)
	g++ -shared -o $(NAME) $(OBJ) $(SFMLFLAG) -g3

all: $(NAME)
	mv $(NAME) ../../../lib/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../../../lib/$(NAME)

re: fclean all


debug: CFLAGS += -g3
debug: $(OBJ)
	@g++ -o $(NAME) $(OBJ) -g3

.PHONY : all clean debug fclean re