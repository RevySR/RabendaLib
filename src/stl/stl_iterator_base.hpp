//
// Created by Rabenda on 09/07/2017.
//

#ifndef RABENDALIB_STL_ITERATOR_BASE_HPP
#define RABENDALIB_STL_ITERATOR_BASE_HPP

#include "stl_config.hpp"

NAMESPACE_BEGIN(stl)
	struct input_iterator_tag {
	};
	struct output_iterator_tag {
	};
	struct forward_iterator_tag : input_iterator_tag {
	};
	struct bidirectional_iterator_tag : forward_iterator_tag {
	};
	struct random_access_iterator_tag : bidirectional_iterator_tag {
	};
	
	template<class _Tp, class _Distance>
	struct input_iterator {
		using iterator_category = input_iterator_tag;
		using value_type = Tp;
		using difference_type = _Distance;
		using pointer = _Tp *;
		using reference = _Tp &;
	};
	
	struct output_iterator {
		using iterator_category = output_iterator_tag;
		using value_type = void;
		using difference_type = void;
		using pointer = void;
		using reference = void;
	};
	
	template<class _Tp, class _Distance>
	struct forward_iterator {
		using iterator_category = forward_iterator_tag;
		using value_type = Tp;
		using difference_type = _Distance;
		using pointer = _Tp *;
		using reference = _Tp &;
	};
	
	template<class _Tp, class _Distance>
	struct bidirectional_iterator {
		using iterator_category = bidirectional_iterator_tag;
		using value_type = Tp;
		using difference_type = _Distance;
		using pointer = _Tp *;
		using reference = _Tp &;
	};
	
	template<class _Tp, class _Distance>
	struct random_access_iterator {
		using iterator_category = random_access_iterator_tag;
		using value_type = Tp;
		using difference_type = _Distance;
		using pointer = _Tp *;
		using reference = _Tp &;
	};
#ifdef __STL_USE_NAMESPACES
	template<class _Category, class _Tp, class _Distance = ptrdiff_t, class _Pointer = _Tp *, class _Reference = _Tp &>
	struct iterator {
		using iterator_category = _Category;
		using value_type = _Tp;
		using difference_type = _Distance;
		using pointer = _Pointer;
		using reference = _Reference;
	};
#endif

#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
	
	template<class _Iterator>
	struct iterator_traits {
		using iterator_category = typename _Iterator::iterator_category;
		using value_type = typename _Iterator::value_type;
		using difference_type = typename _Iterator::difference_type;
		using pointer = typename _Iterator::pointer;
		using reference = typename _Iterator::reference;
	};
	
	template<class _Tp>
	struct iterator_traits<_Tp *> {
		using iterator_traits = random_access_iterator_tag;
		using value_type = _Tp;
		using difference_type = ptrdiff_t;
		using pointer = _Tp *;
		using reference = _Tp &;
	};
	
	template<class _Tp>
	struct iterator_traits<const _Tp *> {
		using iterator_traits = random_access_iterator_tag;
		using value_type = _Tp;
		using difference_type = ptrdiff_t;
		using pointer = const _Tp *;
		using reference = const _Tp &;
	};
	
	template<class _Iter>
	inline typename iterator_traits<_Iter>::iterator_category
	__iterator_category(const _Iter &) {
		using _Category = typename iterator_traits<_Iter>::iterator_category;
		return _Category();
	}
	
	template<class _Iter>
	inline typename iterator_traits<_Iter>::difference_type *
	__distance_type(const _Iter &) {
		return static_cast<typename iterator_traits<_Iter>::difference_type *>(0);
	}
	
	template<class _Iter>
	inline typename iterator_traits<_Iter>::value_type *
	__value_type(const _Iter &) {
		return static_cast<typename iterator_traits<_Iter>::value_type *>(0);
	}
	
	template<class _Iter>
	inline typename iterator_traits<_Iter>::iterator_category
	iterator_category(const _Iter &i) {
		return __iterator_category(i);
	}
	
	template<class _Iter>
	inline typename iterator_traits<_Iter>::difference_type *
	distance_type(const _Iter &i) {
		return __distance_type(i);
	}
	
	template<class _Iter>
	inline typename iterator_traits<_Iter>::value_type *
	value_type(const _Iter &i) {
		return __value_type(i);
	}

#define __ITERATOR_CATEGORY(__i) __iterator_category(__i)
#define __DISTANCE_TYPE(__i) __distance_type(__i)
#define __VALUE_TYPE(__i) __value_type(__i)
#else
	
	template<class _Tp, class _Distance>
	inline input_iterator_tag
	iterator_category(const input_iterator<_Tp, _Distance> &) {
		return input_iterator_tag();
	}
	
	inline output_iterator_tag
	iterator_category(const output_iterator &) {
		return output_iterator_tag();
	}
	
	template<class _Tp, class _Distance>
	inline forward_iterator_tag
	iterator_category(const forward_iterator<_Tp, _Distance> &) {
		return forward_iterator_tag();
	}
	
	template<class _Tp, class _Distance>
	inline bidirectional_iterator_tag
	iterator_category(const bidirectional_iterator<_Tp, _Distance> &) {
		return bidirectional_iterator_tag();
	}
	
	template<class _Tp, class _Distance>
	inline random_access_iterator_tag
	iterator_category(const random_access_iterator<_Tp, _Distance> &) {
		return random_access_iterator_tag();
	}
	
	template<class _Tp>
	inline random_access_iterator_tag
	iterator_category(const _Tp *) {
		return random_access_iterator_tag();
	}
	
	template<class _Tp, class _Distance>
	inline _Tp *value_type(const input_iterator<_Tp, _Distance> &) {
		return (_Tp *) (0);
	}
	
	template<class _Tp, class _Distance>
	inline _Tp *value_type(const forward_iterator<_Tp, _Distance> &) {
		return (_Tp *) (0);
	}
	
	template<class _Tp, class _Distance>
	inline _Tp *value_type(const bidirectional_iterator<_Tp, _Distance> &) {
		return (_Tp *) (0);
	}
	
	template<class _Tp, class _Distance>
	inline _Tp *value_type(const random_access_iterator<_Tp, _Distance> &) {
		return (_Tp *) (0);
	}
	
	template<class _Tp, class _Distance>
	inline _Tp *value_type(const _Tp *) {
		return (_Tp *) (0);
	}
	
	template<class _Tp, class _Distance>
	inline _Distance *distance_type(const input_iterator<_Tp, _Distance> &) {
		return (_Distance *) (0);
	}
	
	template<class _Tp, class _Distance>
	inline _Distance *distance_type(const forward_iterator<_Tp, _Distance> &) {
		return (_Distance *) (0);
	}
	
	template<class _Tp, class _Distance>
	inline _Distance *distance_type(const bidirectional_iterator<_Tp, _Distance> &) {
		return (_Distance *) (0);
	}
	
	template<class _Tp, class _Distance>
	inline _Distance *distance_type(const random_access_iterator<_Tp, _Distance> &) {
		return (_Distance *) (0);
	}
	
	template<class _Tp>
	inline ptrdiff_t *distance_type(const _Tp *) {
		return (ptrdiff_t *) (0);
	}
#define __ITERATOR_CATEGORY(__i) iterator_category(__i)
#define __DISTANCE_TYPE(__i) distance_type(__i)
#define __VALUE_TYPE(__i) value_type(__i)
#endif


NAMESPACE_END(stl)

#endif //RABENDALIB_STL_ITERATOR_BASE_HPP
