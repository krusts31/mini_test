/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 18:13:07 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/04 12:53:11 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "test_func.hpp"

#include <string>

int main ()
{
	/*
	(ft::test(test_3, "Default int constructor"));
	(ft::test(is_default_construct_vec_char_empty, "ft::vector<char> ft_char_vec.empty()"));
	(ft::test(is_default_construct_vec_float_empty, "ft::vector<float> ft_float_vec.empty()"));
	(ft::test(is_default_construct_vec_string_empty, "ft::vector<string> ft_string_vec.empty()"));
	(ft::test(is_default_construct_vec_int_empty, "ft::vector<int> ft_int_vec.empty()"));
	(ft::test(is_fill_constructor_working, "ft::vector<int> fill construcor"));
	*/
	(ft::test(capacity_int_vec_size<int>, "ft::vector<int> ft_vec.capacity()"));
	(ft::test(capacity_int_vec_size<char>, "ft::vector<char> ft_vec.capacity()"));
	(ft::test(capacity_int_vec_size<float>, "ft::vector<float> ft_vec.capacity()"));
	(ft::test(capacity_int_vec_size<std::string>, "ft::vector<std::string> ft_vec.capacity()"));
	std::cout << GREEN << "PASSED: "<< ft::g_passed <<  RED << " FAILED: " << ft::g_failed << RESET << std::endl;
	return (0);
}
