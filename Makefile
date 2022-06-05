VECTOR:=-I ../vector/includes
VECTOR_TESTS:=-I ../vector/tests
TEST_MAIN:=../test_main.cpp
all:
	c++ $(TEST_MAIN) -DMINI_TEST -Wall -Werror -Wextra -pedantic -std=c++98 -I . $(VECTOR) $(VECTOR_TESTS)
clean:
	rm a.out
leaks:
<<<<<<< HEAD
	c++ $(TEST_MAIN) -DMINI_TEST -DLEAKS -Wall -Werror -Wextra -pedantic -std=c++98 -I . $(VECTOR) $(VECTOR_TESTS)
dtest:
	c++ $(TEST_MAIN) -DMINI_TEST -g -fsanitize=address -Wall -Werror -Wextra -pedantic -std=c++98 -I . $(VECTOR) $(VECTOR_TESTS)
=======
	c++ $(TEST_MAIN) -DLEAKS -Wall -Werror -Wextra -pedantic -std=c++98 -I . $(VECTOR) $(VECTOR_TESTS)
>>>>>>> ec0f604c27ddadf66bea8fbd141d3690d45b4365
