#ifndef TEST_HPP
# define TEST_HPP
# include <unistd.h>
# include <vector>
# include <iostream>
# include <string>
# include <csignal>
# include "vector.hpp"
# include "color.hpp"

namespace mini_test
{
	size_t	g_passed = 0;
	size_t	g_failed = 0;

    String list[] = {
            "DEFAULT ",
            "FILL ",
            "FILL_WITH_2_ARGS ",
            "RANGE",
            "COPY"
    };

    String list1[][] = {
            {"PPc", "char **"},
            {"Pc", "char **"},
            {"i", "int"},
            {"f", "float"},
            {"NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE", "std::string"},
            {"c", "char"},
            {"d", "double"}
    };

	template <class T>
	class mini_test
	{
		private:
			T					_arg_1;
			T					_arg_2;
			std::string			_name;
			std::string			_typename;
			std::string			_constructor;
		public:
			explicit mini_test(std::string name,
					bool (*f)(std::vector<T> *, ft::vector<T> *),
					ft::vector<T> *ft_vec,
					std::vector<T> *std_vec,
					int c,
					int size_of_vec,
					T	arg_1,
					T	arg_2) : _arg_1(arg_1), _arg_2(arg_2)
			{
				_typename = typeid(T).name();
				_name = name;

                for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
                {
                    if (c == i)
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
					std::cout << YELLOW
					<< 	_constructor
					<< BOLDWHITE
					<< "ft::vector" 
					<< BOLDMAGENTA 
					<< "<"
					<< MAGENTA 
					<< _typename 
					<< BOLDMAGENTA
					<< ">"
					<< BOLDWHITE
					<< "("
					<< ft_vec->size()
					<< ")."
					<< _name 
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
					<< BOLDWHITE
					<< "("
					<< size_of_vec
					<< ")."
					<< _name 
					<< RESET;
				if (f(std_vec, ft_vec))
				{
					g_passed++;
#ifndef LEAKS
					std::cout << GREEN << "[PASSED] "<< std::endl;
#endif
				}

				else
				{
					g_failed++;
#ifndef LEAKS
					std::cout << RED
						<<  "[FAILED] "
						<< BOLDWHITE
						<< "ft::vector"
						<< BOLDMAGENTA
						<< "<"
						<< MAGENTA
						<< _typename
						<< BOLDMAGENTA
						<< ">"
						<< BOLDWHITE
						<< "("
						<< ft_vec->size()
						<< ")."
						<< _name 
						<< RESET
						<< std::endl;
#endif
				}
			}

			explicit mini_test(std::string name,
					bool (*f)(ft::vector<T> *, ft::vector<T> *),
					ft::vector<T> *ft_vec,
					ft::vector<T> *ft_vec_2,
					int c,
					int size_of_vec,
					T	arg_1,
					T	arg_2) : _arg_1(arg_1), _arg_2(arg_2)
			{
				_typename = typeid(T).name();
				_name = name;

                for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
                {
                    if (c == i)
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
				if (f(ft_vec_2, ft_vec))
				{
					g_passed++;
#ifndef LEAKS
					std::cout << GREEN << "[PASSED] "
						<< BOLDWHITE
						<< "ft::vector" 
						<< BOLDMAGENTA 
						<< "<"
						<< MAGENTA 
						<< _typename 
						<< BOLDMAGENTA
						<< ">"
						<< BOLDWHITE
						<< "("
						<< ft_vec->size()
						<< ")."
						<< _name 
						<< RESET
						<< std::endl;
#endif
				}

				else
				{
					g_failed++;
#ifndef LEAKS
					std::cout << RED
						<<  "[FAILED] "
						<< BOLDWHITE
						<< "ft::vector"
						<< BOLDMAGENTA
						<< "<"
						<< MAGENTA
						<< _typename
						<< BOLDMAGENTA
						<< ">"
						<< BOLDWHITE
						<< "("
						<< ft_vec->size()
						<< ")."
						<< _name 
						<< RESET
						<< std::endl;
#endif
				}
			}
	};
}

#endif
