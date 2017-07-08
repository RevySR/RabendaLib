#ifndef RABENDALIB_STL_TYPE_TRAITS
#define RABENDALIB_STL_TYPE_TRAITS
#include "stl_config.h"

struct true_type{};
struct false_type{};

template<class type>
struct type_traits
{
	using this_dummy_member_must_be_first = true_type;
	using has_trivial_default_constructor = false_type;
	using has_trivial_copy_constructor = false_type;
	using has_trivial_assignment_operator = false_type;
	using has_trivial_destructor = false_type;
	using is_POD_type = false_type;
};

template<>
struct type_traits<char>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<signed char>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<unsigned char>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<short>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<unsigned short>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<int>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<unsigned int>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<long>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<unsigned long>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<long long>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<unsigned long long>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<float>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<double>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<>
struct type_traits<long double>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

template<class T>
struct type_traits<T*>
{
	using has_trivial_default_constructor = true_type;
	using has_trivial_copy_constructor = true_type;
	using has_trivial_assignment_operator = true_type;
	using has_trivial_destructor = true_type;
	using is_POD_type = true_type;
};

#endif
