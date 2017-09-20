#ifndef RABENDALIB_STL_TYPE_TRAITS
#define RABENDALIB_STL_TYPE_TRAITS


#include "stl_config.hpp"

NAMESPACE_BEGIN(stl)
	struct __true_type {
	};
	struct __false_type {
	};
	
	template<class type>
	struct __type_traits {
		using this_dummy_member_must_be_first = __true_type;
		using has_trivial_default_constructor = __false_type;
		using has_trivial_copy_constructor = __false_type;
		using has_trivial_assignment_operator = __false_type;
		using has_trivial_destructor = __false_type;
		using is_POD_type = __false_type;
	};
	
	template<>
	struct __type_traits<char> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<signed char> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<unsigned char> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<short> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<unsigned short> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<int> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<unsigned int> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<long> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<unsigned long> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<long long> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<unsigned long long> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<float> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<double> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<>
	struct __type_traits<long double> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	template<class T>
	struct __type_traits<T *> {
		using has_trivial_default_constructor = __true_type;
		using has_trivial_copy_constructor = __true_type;
		using has_trivial_assignment_operator = __true_type;
		using has_trivial_destructor = __true_type;
		using is_POD_type = __true_type;
	};
	
	
	template<class Type, Type value>
	struct integral_constant {
		using value_type = Type;
		using type = integral_constant<Type, value>;
		static constexpr const value_type value = value;
		
		constexpr operator value_type() { return value; }
		
		constexpr value_type operator()() { return value; }
	};
	
	using true_type = integral_constant<bool, true>;
	using false_type = integral_constant<bool false>;


//! Select Type
	template<bool flag, typename T, typename U>
	struct conditional {
		using type = T;
	};
	
	template<typename T, typename U>
	struct conditional<false, T, U> {
		using type = U;
	};
	
	template<bool flag, typename T, typename U>
	using conditional_t = typename conditional<flag, T, U>::type;

//! Select Bool
	template<bool flag, bool T, bool U>
	struct t_if : public integral_constant<bool, T> {
	};
	template<bool T, bool U>
	struct t_if<false, T, U> : public integral_constant<bool, U> {
	};

//! SFINAE
	template<bool flag, typename T = void>
	struct enable_if {
	};
	template<typename T>
	struct enable_if<true, T> {
		using type = T;
	};
	
	template<bool flag, typename T> using enable_if_t = typename enable_if<flag, T>::type;


//! traits
	template<typename T>
	struct remove_const {
		using type = T;
	};
	template<typename T>
	struct remove_const<T const> {
		using type = T;
	};
	template<typename T> using remove_const_t = typename remove_const<T>::type;
	
	template<typename T>
	struct remove_volatile {
		using type = T;
	};
	template<typename T>
	struct remove_volatile<T volatile> {
		using type = T;
	};
	template<typename T> using remove_volatile_t = typename remove_volatile<T>::type;
	
	template<typename T>
	struct remove_cv {
		using type = remove_const_t<remove_volatile_t<T>>;
	};
	template<typename T> using remove_cv_t = typename remove_cv<T>::type;
	
	
	template<typename T>
	struct add_const {
		using type = T const;
	};
	template<typename T>
	struct add_const<T const> {
		using type = T const;
	};
	template<typename T> using add_const_t = typename add_const<T>::type;
	
	template<typename T>
	constexpr add_const_t<T> &as_const(T &v) { return v; }
	
	template<typename T>
	void as_const(T &&v) = delete;
	
	template<typename T>
	struct add_volatile {
		using type = T volatile;
	};
	template<typename T>
	struct add_volatile<T volatile> {
		using type = T volatile;
	};
	template<typename T> using add_volatile_t = typename add_volatile<T>::type;
	
	template<typename T>
	struct add_cv {
		using type = add_const_t<add_volatile_t<T>>;
	};
	template<typename T> using add_cv_t = typename add_cv<T>::type;
NAMESPACE_END(stl)
#endif
