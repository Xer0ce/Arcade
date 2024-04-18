##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = arcade_sdl2.so

SRC = ../ADisplay.cpp \
	  ./SDL.cpp \
	  ../AEntity.cpp \
	  ./EntitySDL.cpp \

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -std=c++20 -fPIC

SDLFLAG = -lSDL2 -lSDL2_image -lSDL2_ttf

$(NAME): $(OBJ)
	g++ -shared -o $(NAME) $(OBJ) $(SDLFLAG) -g3

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
