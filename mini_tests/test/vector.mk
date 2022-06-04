FLAGS := -Wall -Werror -Wextra -std=c++14
CC := c++

HEADER=../vector
SRC=test_vector.cpp

all:
	$(CC) $(FLAGS) test_vector.cpp -I $(HEADER) ../.obj/vector/vector.o
test:
