NAME = mutant

SRC = main.cpp

HDR = MutantStack.h

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++98


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(LDFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	- $(RM) $(OBJ)

fclean: clean
	- $(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: re fclean clean all