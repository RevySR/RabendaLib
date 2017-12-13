//
// Created by Rabenda on 13/12/2017.
//

#ifndef RABENDALIB_SEMIGROUP_HPP
#define RABENDALIB_SEMIGROUP_HPP

#include "config.hpp"

NAMESPACE_BEGIN(MONAD)
	
	
	template<class T>
	struct Semigroup {
		static T append(T const &a, T const &b) {
			return a + b;
		}
	};
	
	template<class T>
	static T append(T const &a, T const &b) {
		return Semigroup<T>::append(a, b);
	}

NAMESPACE_END(MONAD)


#endif //RABENDALIB_SEMIGROUP_HPP
