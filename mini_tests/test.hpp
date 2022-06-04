#ifndef TEST_HPP
# define TEST_HPP
# include <unistd.h>
# include <iostream>
# include <string>
# include <csignal>

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
	typedef bool (*t_func)(void);
	typedef t_func TEST;

	size_t	g_passed = 0;
	size_t	g_failed = 0;

	void signalPass(int signum)
	{
		(void)signum;
		g_passed++;
		signal(SIGUSR1, signalPass);
	}

	void signalFail(int signum)
	{
		(void)signum;
		g_failed++;
		signal(SIGUSR2, signalFail);
	}

	class	test
	{
		private:
			std::string	name;
			pid_t 		pid;
		public:
			test(t_func f, std::string n, pid_t p = getpid()): name(n), pid(p)
			{
				if (f())
				{
					kill(pid, SIGUSR1);
					std::cout << GREEN << name << " PASSED" << RESET << std::endl;
				}
				else
				{
					kill(pid, SIGUSR2);
					std::cout << RED << name << " FAILED" << RESET << std::endl;
				}
			}
	};
}

#endif
