NAME = bureaucrates

SRC = main.cpp Bureaucrat.cpp

OBJ = $(SRC:.cpp=.o)

HDR = Bureaucrat.h

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

.PHONY: all re clean fclean