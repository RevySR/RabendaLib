#ifndef RABENDALIB_STL_ITERATOR
#define RABENDALIB_STL_ITERATOR

#include "stl_config.hpp"

NAMESPACE_BEGIN(stl)
//dispatch tag









//distance
template<class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type
__distance(InputIterator first, InputIterator last, input_iterator_tag)
{
	typename iterator_traits<InputIterator>::difference_type n = 0;
	while (first != last)
	{
		++first;
		++n;
	}
	return n;
}

template<class RandomAccessIterator>
inline typename iterator_traits<RandomAccessIterator>::difference_type
__distance(RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag)
{
	return last - first;
}

template<class InputIterator>
inline typename iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last)
{
	using category = typename iterator_traits<InputIterator>::iterator_category;
	return __distance(first, last, category());
}

//advance
template<class Inputerator, class Distance>
inline void
__advance(Inputerator& i, Distance n, input_iterator_tag)
{
	while (n--) ++i;
}

template<class BidirectionalIterator, class Distance>
inline void
__advance(BidirectionalIterator& i, Distance n, bidirectional_iterator_tag)
{
	if (n >= 0)
		while (n--) ++i;
	else
		while (n++) --i;
}

template<class RandomAccessIterator, class Distance>
inline void
__advance(RandomAccessIterator& i, Distance n, random_access_iterator_tag)
{
	i += n;
}

template<class InputIterator, class Distance>
inline void
advance(InputIterator& i, Distance n)
{
	__advance(i, n, iterator_category(i));
}


NAMESPACE_END(stl)

#endif // RABENDALIB_STL_ITERATOR
