##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = arcade_ncurses.so

SRC = ../ADisplay.cpp \
	  ./NCurses.cpp \
	  ./Entity.cpp \
	  ../AEntity.cpp \

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -std=c++20 -fPIC -g3

NCURSESFLAG = -lncurses

$(NAME): $(OBJ)
	g++ -shared -o $(NAME) $(OBJ) $(NCURSESFLAG)

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
