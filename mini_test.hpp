#ifndef TEST_HPP
# define TEST_HPP
# include <unistd.h>
# include <vector>
# include <iostream>
# include <string>
# include <csignal>
# include "vector.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

namespace mini_test
{
	enum constructor{def, fill, fill_2, range, copy};
	size_t	g_passed = 0;
	size_t	g_failed = 0;

	template <class T>
	class mini_test
	{
		private:
			std::string			_name;
			std::string			_typename;
		public:
			explicit mini_test(std::string name, bool (*f)(std::vector<T> *, ft::vector<T> *), ft::vector<T> *ft_vec, std::vector<T> *std_vec, int c): _name(name)
			{
				if (f(std_vec, ft_vec))
				{
					_typename = typeid(T).name();
					g_passed++;
<<<<<<< HEAD:mini_test.hpp
					//so if we go in here we can get the artributes from the vector class
#ifndef LEAKS
					std::cout << GREEN << "[PASSED] " << BOLDWHITE << "ft::vector" << BOLDMAGENTA << "<" << MAGENTA << typeid(T).name() << BOLDMAGENTA << ">" << BOLDWHITE << _name  << RESET << std::endl;
=======
#ifndef LEAKS
					std::cout << GREEN << "[PASSED] " << BOLDMAGENTA << "<" << MAGENTA << typeid(T).name() << BOLDMAGENTA << ">" << BOLDWHITE << _name  << RESET << std::endl;
>>>>>>> ec0f604c27ddadf66bea8fbd141d3690d45b4365:test.hpp
#endif
				}

				else
				{
					g_failed++;
#ifndef LEAKS
<<<<<<< HEAD:mini_test.hpp
					std::cout << RED <<  "[FAILED] " <<  BOLDWHITE << "ft::vector" << BOLDMAGENTA << "<" << MAGENTA << typeid(T).name() << BOLDMAGENTA << ">" << BOLDWHITE << _name  << RESET << std::endl;
=======
					std::cout << RED <<  "[FAILED]" << BOLDMAGENTA << "<" << MAGENTA << typeid(T).name() << BOLDMAGENTA << ">" << BOLDWHITE << _name  << RESET << std::endl;
>>>>>>> ec0f604c27ddadf66bea8fbd141d3690d45b4365:test.hpp
#endif
				}
			}
	};
}

#endif

