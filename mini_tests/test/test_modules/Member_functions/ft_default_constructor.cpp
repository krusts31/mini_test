/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_default_constructor.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 12:26:59 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/05/31 12:27:00 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "vector.hpp"
#include "test_class.hpp"

int	main()
{
#ifdef TIME
	#include <chrono>
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
#endif
	ft::vector<int>				test_int;
	ft::vector<std::string>		test_str;
	ft::vector<float>			test_float;
	ft::vector<char>			test_char;
	ft::vector<test_class>		test_vc;

#ifdef LEAKS
	system("leaks ft_out");
#endif
#ifdef TIME
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;

	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " µs" << std::endl;

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

	std::cout << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " sec" << std::endl;
#endif
	return (0);
}
