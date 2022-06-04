all:
	c++ main.cpp -Wall -Werror -Wextra -pedantic -std=c++98 -I . 
clean:
	rm a.out
