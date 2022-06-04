VECTOR:=-I ../vector/includes
VECTOR_TESTS:=-I ../vector/tests
TEST_MAIN:=../test_main.cpp
all:
	c++ $(TEST_MAIN) -Wall -Werror -Wextra -pedantic -std=c++98 -I . $(VECTOR) $(VECTOR_TESTS)
clean:
	rm a.out
