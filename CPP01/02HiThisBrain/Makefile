NAME = HiThisBrain.out

CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f *.out && rm -f *.o

re: fclean all

.PHONY: all clean fclean re