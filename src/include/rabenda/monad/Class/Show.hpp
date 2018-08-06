//
// Created by Rabenda on 13/12/2017.
//

#ifndef RABENDALIB_SHOW_HPP
#define RABENDALIB_SHOW_HPP


#include <rabenda/lib_common.hpp>
#include <sstream>
#include <type_traits>

NAMESPACE_BEGIN(MONAD)
	
	template<class T>
	struct Show {
		static std::string show(T const &value) {
			if constexpr (std::is_same_v<T,
				std::string>) {
				return static_cast<T>(value);
			} else {
				std::ostringstream stream;
				stream << value;
				return stream.str();
			}
		}
	};
	
	template<class T>
	static std::string show(T const &value) {
		return Show<T>::show(value);
	}

NAMESPACE_END(MONAD)


#endif //RABENDALIB_SHOW_HPP
