//
// Created by Rabenda on 13/12/2017.
//

#ifndef RABENDALIB_APPLICATIVE_HPP
#define RABENDALIB_APPLICATIVE_HPP

#include <rabenda/lib_common.hpp>
#include <utility>
#include <rabenda/monad/Class/Apply.hpp>

NAMESPACE_BEGIN(MONAD)
	template<template<class> class F>
	class Applicative {
		template<class T>
		static F<T> pure(T &&value) = delete;
	};
	
	template<template<class> class F, class T>
	static F<T> pure(T &&value) {
		return Applicative<F>::pure(std::forward<T>(value));
	};

NAMESPACE_END(MONAD)


#endif //RABENDALIB_APPLICATIVE_HPP
