#ifndef TEST_HPP
# define TEST_HPP
# include <unistd.h>
# include <iostream>
# include <string>
# include <csignal>

#define TEST(type)  \
bool checkmin(type, __FUNCTION__, __LINE__);

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

namespace ft
{
	size_t	g_passed = 0;
	size_t	g_failed = 0;

	class test
	{
		private:
			std::string	name;
		public:
			test(bool (*f)(void), std::string n): name(n)
			{
				if (f())
				{
					g_passed++;
					std::cout << GREEN << name << " PASSED" << RESET << std::endl;
				}
				else
				{
					g_failed++;
					std::cout << RED << name << " FAILED" << RESET << std::endl;
				}
			}
	};
}

#endif