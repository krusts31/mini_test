/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   std_default_constructor.cpp                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 19:31:04 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/05/31 12:28:22 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include "test_class.hpp"

int	main()
{
#ifdef TIME
	#include <chrono>
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
#endif

	std::vector<int>			test_int;
	std::vector<std::string>	test_str;
	std::vector<float>			test_float;
	std::vector<char>			test_char;
	std::vector<test_class>		test_vc;

#ifdef LEAKS
	system("leaks std_out");
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
