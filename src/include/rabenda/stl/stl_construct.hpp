//
// Created by Rabenda on 09/07/2017.
//

#ifndef RABENDALIB_STL_CONSTRUCT_H
#define RABENDALIB_STL_CONSTRUCT_H

#include <rabenda/stl/stl_config.hpp>
#include <rabenda/stl/stl_iterator.hpp>
#include <rabenda/stl/type_traits.hpp>

NAMESPACE_BEGIN(stl)
	template<class _T1, class _T2>
	inline void _Construct(_T1 *__p, const _T2 &__value) {
		new((void *) __p) _T1(__value);
	}
	
	template<class _T1>
	inline void _Construct(_T1 *__p) {
		new((void *) __p) _T1();
	}
	
	template<class _Tp>
	inline void _Destroy(_Tp *__pointer) {
		__pointer->~();
	}
	
	template<class _ForwardIterator>
	inline void __destroy_aux(_ForwardIterator __first, _ForwardIterator __last, __false_type) {
		for (; __first < __last; ++__first)
			destroy(&*__first);
	}
	
	template<class _ForwardIterator>
	inline void __destroy_aux(_ForwardIterator, _ForwardIterator, __true_type) {}
	
	template<class _ForwardIterator, class _Tp>
	inline void __destroy(_ForwardIterator __first, _ForwardIterator __last, _Tp *) {
		using _Trivial_destructor = typename __type_traits<_Tp>::has_trivial_destructor;
		__destroy(__first, __last, _Trivial_destructor());
	}
	
	
	template<class _ForwardIterator>
	inline void _Destroy(_ForwardIterator __first, _ForwardIterator __last) {
		__destroy(__first, __last, value_type(__first));
	}

#define __DESTROY_GEN(TYPE) \
    inline void _Destroy(TYPE*, TYPE*) {}
	
	__DESTROY_GEN(char)
	
	__DESTROY_GEN(signed
		              char)
	
	__DESTROY_GEN(unsigned
		              char)
	
	__DESTROY_GEN(short)
	
	__DESTROY_GEN(unsigned
		              short)
	
	__DESTROY_GEN(int)
	
	__DESTROY_GEN(unsigned)
	
	__DESTROY_GEN(long)
	
	__DESTROY_GEN(unsigned
		              long)
	
	__DESTROY_GEN(long
		              long)
	
	__DESTROY_GEN(unsigned
	              long
		              long)
	
	__DESTROY_GEN(float)
	
	__DESTROY_GEN(double)
	
	__DESTROY_GEN(long
		              double)
	
	__DESTROY_GEN(wchar_t)
	
	__DESTROY_GEN(char16_t)
	
	__DESTROY_GEN(char32_t)

#undef DESTROY_GEN
	
	
	template<class _T1, class _T2>
	inline void construct(_T1 *__p, const _T2 &__value) {
		_Construct(__p, __value);
	}
	
	template<class _T1>
	inline void construct(_T1 *__p) {
		_Construct(__p);
	}
	
	template<class _Tp>
	inline void destroy(_Tp *__pointer) {
		_Destroy(__pointer);
	}
	
	template<class _ForwardIterator>
	inline void destroy(_ForwardIterator __first, _ForwardIterator __last) {
		_Destroy(__first, __last);
	}

NAMESPACE_END(stl)

#endif //RABENDALIB_STL_CONSTRUCT_H
