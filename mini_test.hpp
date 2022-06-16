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

	void signalHandler(int signum)
	{
		(void)signum;
		std::cout << CYAN << "[SEGFAULT] " << RESET << std::endl;
		exit(1);
	}

	template <class T>
	class mini_test
	{
		private:
			T					_arg_1;
			T					_arg_2;
			std::string			_name;
			std::string			_typename;
			std::string			_constructor;
			int 				_c;
			int 				_size_of_vec;
		public:
			void	get_constructor(void)
			{
				if (_c == fill)
					std::cout << "(" << _size_of_vec << ").";
				if (_c == fill_2)
				{
					if (_typename.compare("char *") != 0)
						std::cout << "(" << _size_of_vec << ", " << _arg_2 << ").";
				}
				if (_c == range)
					std::cout << "coming sooon";
				if (_c == copy)
					std::cout << "coming sooon";
			}
			explicit mini_test(std::string name,
					bool (*f)(std::vector<T> *, ft::vector<T> *),
					ft::vector<T> *ft_vec,
					std::vector<T> *std_vec,
					int c,
					int size_of_vec,
					T	arg_1,
					T	arg_2) : _arg_1(arg_1), _arg_2(arg_2)
			{
				signal(SIGSEGV, signalHandler);
				_typename = typeid(T).name();
				_name = name;
				_size_of_vec = size_of_vec;
				_c = c;
				if (_typename.compare("PPc") == 0)
					_typename = "char **";
				if (_typename.compare("Pc") == 0)
					_typename = "char *";
				if (_typename.compare("i") == 0)
					_typename = "int";
				if (_typename.compare("f") == 0)
					_typename = "float";
				if (_typename.compare("NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE") == 0)
					_typename = "std::string";
				if (_typename.compare("c") == 0)
					_typename = "char";
				if (_typename.compare("d") == 0)
					_typename = "double";
				if (f(std_vec, ft_vec))
				{
					g_passed++;
#ifndef LEAKS
				std::cout << GREEN << "[PASSED] " << RESET
				BOLDWHITE
				<< "ft::vector" 
				<< BOLDMAGENTA 
				<< "<"
				<< MAGENTA 
				<< _typename 
				<< BOLDMAGENTA
				<< ">"
				<< BOLDWHITE;

				get_constructor();

				std::cout << _name 
				<< RESET
				<< " == " 
				<< BOLDWHITE
				<< "std::vector"
				<< BOLDMAGENTA 
				<< "<"
				<< MAGENTA 
				<< _typename 
				<< BOLDMAGENTA
				<< ">"
				<< BOLDWHITE;
				get_constructor();
				std::cout << _name 
				<< RESET << std::endl;
#endif
				}
				else
				{
					g_failed++;
#ifndef LEAKS
				std::cout << RED << "[FAILED] " << RESET
				<< BOLDWHITE
				<< "ft::vector" 
				<< BOLDMAGENTA 
				<< "<"
				<< MAGENTA 
				<< _typename 
				<< BOLDMAGENTA
				<< ">"
				<< BOLDWHITE;

				get_constructor();

				std::cout << _name 
				<< RESET
				<< " == " 
				<< BOLDWHITE
				<< "std::vector"
				<< BOLDMAGENTA 
				<< "<"
				<< MAGENTA 
				<< _typename 
				<< BOLDMAGENTA
				<< ">"
				<< BOLDWHITE;
				get_constructor();
				std::cout << _name 
				<< RESET << std::endl;
#endif
				}
			}
			/*
			 *	ft::vector<int>(1, 2).begin() == std::vector<int>(1, 2).begin()
			 */
			explicit mini_test(std::string name,
					bool (*f)(ft::vector<T> *, ft::vector<T> *),
					ft::vector<T> *ft_vec,
					ft::vector<T> *ft_vec_2,
					int c,
					int size_of_vec,
					T	arg_1,
					T	arg_2) : _arg_1(arg_1), _arg_2(arg_2)
			{
				signal(SIGSEGV, signalHandler);
				_typename = typeid(T).name();
				_name = name;
				_size_of_vec = size_of_vec;
				_c = c;
				if (c == def)
					_constructor = "DEFAULT ";
				if (c == fill)
					_constructor = "FILL ";
				if (c == fill_2)
					_constructor = "FILL_WITH_2_ARGS ";
				if (c == range)
					_constructor = "RANGE";
				if (c == copy)
					_constructor = "COPY";
				if (_typename.compare("PPc") == 0)
					_typename = "char **";
				if (_typename.compare("Pc") == 0)
					_typename = "char *";
				if (_typename.compare("i") == 0)
					_typename = "int";
				if (_typename.compare("f") == 0)
					_typename = "float";
				if (_typename.compare("NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE") == 0)
					_typename = "std::string";
				if (_typename.compare("c") == 0)
					_typename = "char";
				if (_typename.compare("d") == 0)
					_typename = "double";
				if (f(ft_vec_2, ft_vec))
				{
					g_passed++;
#ifndef LEAKS
					std::cout << GREEN << "[PASSED] " << RESET
					BOLDWHITE
					<< "ft::vector" 
					<< BOLDMAGENTA 
					<< "<"
					<< MAGENTA 
					<< _typename 
					<< BOLDMAGENTA
					<< ">"
					<< BOLDWHITE;

					get_constructor();

					std::cout << _name 
					<< RESET
					<< " == " 
					<< BOLDWHITE
					<< "ft::vector"
					<< BOLDMAGENTA 
					<< "<"
					<< MAGENTA 
					<< _typename 
					<< BOLDMAGENTA
					<< ">"
					<< BOLDWHITE;
					get_constructor();
					std::cout << _name 
					<< RESET << std::endl;
#endif
				}
				else
				{
					g_failed++;
#ifndef LEAKS
					std::cout << RED << "[FAILED] " << RESET
					<< BOLDWHITE
					<< "ft::vector" 
					<< BOLDMAGENTA 
					<< "<"
					<< MAGENTA 
					<< _typename 
					<< BOLDMAGENTA
					<< ">"
					<< BOLDWHITE;

					get_constructor();

					std::cout << _name 
					<< RESET
					<< " == " 
					<< BOLDWHITE
					<< "std::vector"
					<< BOLDMAGENTA 
					<< "<"
					<< MAGENTA 
					<< _typename 
					<< BOLDMAGENTA
					<< ">"
					<< BOLDWHITE;
					get_constructor();
					std::cout << _name
					<< RESET
					<< " == " 
					<< BOLDWHITE
					<< "ft::vector"
					<< BOLDMAGENTA 
					<< "<"
					<< MAGENTA 
					<< _typename 
					<< BOLDMAGENTA
					<< ">"
					<< BOLDWHITE;
					get_constructor();
					std::cout << _name 
					<< RESET << std::endl;
			}
#endif
		}
	};
}
#endif
