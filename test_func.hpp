#include "vector.hpp"

#include <vector>
#include <string>

bool	test_3(void)
{
	ft::vector<int>	ft_int_vec;
	return (true);
}

bool	is_default_construct_vec_int_empty(void)
{
	ft::vector<int>			ft_int_vec;

	if (ft_int_vec.empty())
		return (true);
	else
		return (false);
}

bool	is_default_construct_vec_char_empty(void)
{
	ft::vector<char>			ft_char_vec;

	if (ft_char_vec.empty())
		return (true);
	else
		return (false);
}

bool	is_default_construct_vec_string_empty(void)
{
	ft::vector<std::string>		string_vec;

	if (string_vec.empty())
		return (true);
	else
		return (false);
}

bool	is_default_construct_vec_float_empty(void)
{
	ft::vector<float>			ft_float_vec;

	if (ft_float_vec.empty())
		return (true);
	else
		return (false);
}

bool	is_fill_constructor_working(void)
{
	ft::vector<int>		to_copie(4);

	return (false);
}

bool	capacity_int_vec_size(void)
{
	ft::vector<int>			ft_vec(4);
	std::vector<int>		std_vec(4);

	if (ft_vec.capacity() == std_vec.capacity())
		return (true);
	else
		return (false);
}

bool	test_time(void)
{
	
	return (true);
}
