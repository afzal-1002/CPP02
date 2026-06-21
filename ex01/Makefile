Name= fixed-point

CPP = c++
CPPFLAGS	= 	-Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp

OBJS = $(SRC:.cpp=.o)

all:$(Name)

$(Name):$(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(Name)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(Name)

re: fclean all

.PHONY: all clean fclean re