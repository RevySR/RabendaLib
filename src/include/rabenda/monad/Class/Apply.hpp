//
// Created by Rabenda on 13/12/2017.
//

#ifndef RABENDALIB_APPLY_HPP
#define RABENDALIB_APPLY_HPP

#include <rabenda/lib_common.hpp>
#include <utility>
#include <rabenda/monad/Class/Functor.hpp>

NAMESPACE_BEGIN(MONAD)
	template<template<class> class F>
	class Apply {
		template<class Func, class A>
		static auto apply1(
			F<Func> const &func,
			F<A> const &a
		) -> F<decltype(std::declval<Func const>()(std::declval<A const>()))> = delete;
	};
	
	template<template<class> class F, class Func, class Head>
	static auto applyN(F<Func> const &func, F<Head> const &head) {
		return Apply<F>::apply1(func, head);
	};
	
	template<template<class> class F, class Func, class Head, class... Rest>
	static auto applyN(F<Func> const &func, F<Head> const &head, F<Rest> const &... rest) {
		return applyN(applyN(func, head), rest...);
	};
	
	template<template<class> class F, class Func, class Head>
	static auto liftN(Func const &func, F<Head> const &head) {
		return map(func, head);
	};
	
	template<template<class> class F, class Func, class Head, class... Rest>
	static auto liftN(Func const &func, F<Head> const &head, F<Rest> const &... rest) {
		return applyN(liftN(func, head), rest...);
	};


NAMESPACE_END(MONAD)


#endif //RABENDALIB_APPLY_HPP
