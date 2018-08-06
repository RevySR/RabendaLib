//
// Created by Rabenda on 13/12/2017.
//

#ifndef RABENDALIB_FUNCTOR_HPP
#define RABENDALIB_FUNCTOR_HPP


#include <rabenda/lib_common.hpp>
#include <utility>

NAMESPACE_BEGIN(MONAD)
	
	template<template<class> class F>
	struct Functor {
		template<class Func, class A>
		static auto map(
			Func const &func,
			F<A> const &a
		) -> F<decltype(func(std::devlval<A const()>))> = delete;
	};
	
	
	template<template<class> class F, class Func, class A>
	static auto map(
		Func const &func,
		F<A> const &a
	) {
		return Functor<F>::map(func, a);
	};

NAMESPACE_END(MONAD)


#endif //RABENDALIB_FUNCTOR_HPP
