#ifndef TEST_HPP
# define TEST_HPP
# include <unistd.h>
# include <vector>
# include <iostream>
# include <string>
# include <csignal>
//# include "vector.hpp"
# include "color.hpp"

namespace mini_test
{
	size_t	g_passed = 0;
	size_t	g_failed = 0;

	enum constructor{def, fill, fill_2, range, copy};
	std::string list[] = {
            "DEFAULT ",
            "FILL ",
            "FILL_WITH_2_ARGS ",
            "RANGE",
            "COPY"
    };

	std::string list1[7][2] = {
            {"PPc", "char **"},
            {"Pc", "char **"},
            {"i", "int"},
            {"f", "float"},
            {"NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE", "std::string"},
            {"c", "char"},
            {"d", "double"}
    };

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
			int 				_c;
			int 				_size_of_vec;
			std::string			_constructor;
		public:
			void	inti_vars(void)
			{
                for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
                {
                    if (_c == i)
                    {
                        _constructor = list[i];
                        break ;
                    }
                }

                for (int i = 0; i < 7; i++)
                {
                    if (_typename.compare(list1[i][i]))
                    {
                        _typename = list1[i][1];
                        break ;
                    }
                }
			}
			void	std_print_ok(void)
			{
#ifndef LEAKS
				std::cout << GREEN << "[OK] "
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
			void	std_print_ko(void)
			{
#ifndef LEAKS
				std::cout << RED << "[KO] "
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
			void	ft_print_ok(void)
			{
#ifndef LEAKS
				std::cout << GREEN << "[OK] "
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
			void	ft_print_ko(void)
			{
#ifndef LEAKS
				std::cout << RED << "[KO] "
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
			void	get_constructor(void)
			{
				if (_c == def)
					std::cout << "().";
				if (_c == fill)
					std::cout << "(" << _size_of_vec << ").";
				if (_c == fill_2)
				{
					if (_typename.compare("char *") == 0)
						std::cout << "(" << _size_of_vec << ", \"\").";
					else
						std::cout << "(" << _size_of_vec << ", " << _arg_2 << ").";
				}
				if (_c == range)
					std::cout << "coming sooon";
				if (_c == copy)
					std::cout << "coming sooon";
			}
			explicit mini_test(
					std::string name,
					bool (*f)(std::vector<T> *, ft::vector<T> *),
					ft::vector<T> *ft_vec,
					std::vector<T> *std_vec,
					int c,
					int size_of_vec,
					T	arg_1,
					T	arg_2): _name(name), _c(c), _size_of_vec(size_of_vec), _arg_1(arg_1), _arg_2(arg_2)
			{
				inti_vars();
				signal(SIGSEGV, signalHandler);
				if (f(std_vec, ft_vec))
				{
					std_print_ok();
					g_passed++;
				}
				else
				{
					std_print_ko();
					g_failed++;
				}
			}

			explicit mini_test(std::string name,
					bool (*f)(ft::vector<T> *, ft::vector<T> *),
					ft::vector<T> *ft_vec,
					ft::vector<T> *ft_vec_2,
					int c,
					int size_of_vec,
					T	arg_1,
					T	arg_2): _name(name), _c(c), _size_of_vec(size_of_vec), _arg_1(arg_1), _arg_2(arg_2)
			{
				inti_vars();
				signal(SIGSEGV, signalHandler);
				if (f(ft_vec, ft_vec_2))
				{
					ft_print_ok();
					g_passed++;
				}
				else
				{
					ft_print_ko();
					g_failed++;
				}
			}
	};
}
#endif
