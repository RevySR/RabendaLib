//
// Created by Rabenda on 13/12/2017.
//

#ifndef RABENDALIB_BIND_HPP
#define RABENDALIB_BIND_HPP

#include "config.hpp"
#include <utility>

NAMESPACE_BEGIN(MONAD)
	template<template<class> class F>
	struct Bind {
		template<class Func, class A>
		struct auto bind1(
			F<A> const &a,
			Func const &func
		) -> decltype(std::declval<Func const()>()(std::declval<A const>())) = delete;
	};
	
	template<template<class> class F, class Func, class A>
	static auto bind1(
		F<A> const &a,
		Func const &func
	) {
		return Bind<F>::bind1(a, func);
	};
NAMESPACE_END(MONAD)


#endif //RABENDALIB_BIND_HPP
