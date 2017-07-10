//
// Created by Rabenda on 10/07/2017.
//

#ifndef RABENDALIB_DEFALLOC_HPP
#define RABENDALIB_DEFALLOC_HPP

#include "stl_config.hpp"
#include "stl_algobase.hpp"

NAMESPACE_BEGIN(stl)
	
	template<class T>
	inline T *allocate(ptrdiff_t size, T *) {
		set_new_handler(nullptr);
		T *tmp = (T *) (::operator new((size_t) (size * sizeof(T))));
		if (tmp == nullptr) {
			cerr << "out of memory" << endl;
			exit(1);
		}
		return tmp;
	}
	
	template<class T>
	inline void deallocate(T *buffer) {
		::operator delete(buffer);
	}
	
	template<class T>
	class allocator {
		using value_type = T;
		using pointer = T *;
		using const_pointer = const T *;
		using reference = T &;
		using const_reference = const T &;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		
		pointer allocate(size_type n) {
			return NAMESPACE_GET(stl)::allocate((difference_type) n, (pointer) 0);
		}
		
		void deallocate(pointer p) {
			NAMESPACE_GET(stl)::deallocate(p);
		}
		
		size_type init_page_size() {
			return NAMESPACE_GET(stl)::max(size_type(1), size_type(4096 / sizeof(T)));
		}
		
		size_type max_size() const {
			return NAMESPACE_GET(stl)::max(size_type(1), size_type(UINT_MAX / sizeof(T)));
		}
	};
	
	template<>
	class allocator<void> {
		using pointer = void *;
	};


NAMESPACE_END(stl)

#endif //RABENDALIB_DEFALLOC_HPP
