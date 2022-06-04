VECTOR:=-I ../vector/includes
all:
	c++ main.cpp -Wall -Werror -Wextra -pedantic -std=c++98 -I . $(VECTOR) 
clean:
	rm a.out
