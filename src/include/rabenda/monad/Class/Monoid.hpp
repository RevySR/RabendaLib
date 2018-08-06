//
// Created by Rabenda on 13/12/2017.
//

#ifndef RABENDALIB_MONOID_HPP
#define RABENDALIB_MONOID_HPP

#include <rabenda/lib_common.hpp>

NAMESPACE_BEGIN(MONAD)
	
	template<class T>
	struct Monoid {
		static T mempty() {
			return T{};
		}
	};
	
	template<class T>
	static T mempty() {
		return Monoid<T>::mempty();
	}

NAMESPACE_END(MONAD)


#endif //RABENDALIB_MONOID_HPP
