#ifndef RABENDALIB_STL_PAIR
#define RABENDALIB_STL_PAIR

#include "stl_config.hpp"
NAMESPACE_BEGIN(stl)
template<class T1, class T2>
struct pair
{
	using first_type = T1;
	using second_type = T2;
	
	first_type first;
	second_type second;

	pair():first(first_type()), second(second_type()){}
	pair(const first_type& a, const second_type& b): first(a), second(b){}
	template<class U1, class U2>
	pair(const pair<U1, U2>& p):first(p.first), second(p.second){}
};

template<class T1, class T2>
inline bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return x.first == y.first && x.second == y.second;
}

template<class T1, class T2>
inline bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return x.first < y.first || (!(y.first < x.first)) && x.second < y.second;
}

template<class T1, class T2>
inline bool operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return !(x == y);
}

template<class T1, class T2>
inline bool operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return y < x;
}

template<class T1, class T2>
inline bool operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return !(y > x);
}

template<class T1, class T2>
inline bool operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return !(x < y);
}

template<class T1, class T2>
inline pair<T1, T2> make_pair(const T1& x, const T2& y)
{
	return pair<T1, T2>(x, y);
}

NAMESPACE_END(stl)

#endif //RABENDALIB_STL_PAIR
