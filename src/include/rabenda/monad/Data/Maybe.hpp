//
// Created by Rabenda on 14/12/2017.
//

#ifndef RABENDALIB_MAYBE_HPP
#define RABENDALIB_MAYBE_HPP

#include <rabenda/lib_common.hpp>
#include <optional>
#include <rabenda/monad/Class/Show.hpp>
#include <rabenda/monad/Class/Functor.hpp>
#include <rabenda/monad/Class/Semigroup.hpp>
#include <rabenda/monad/Class/Monoid.hpp>
#include <rabenda/monad/Class/Apply.hpp>
#include <rabenda/monad/Class/Applicative.hpp>
#include <rabenda/monad/Class/Bind.hpp>

NAMESPACE_BEGIN(MONAD)
    template<class T>
    using Maybe = std::optional<T>;

    template<class T>
    Maybe<T> Just(T &&value) {
        return Maybe<T>{std::forward(value)};
    }

    template<class T>
    Maybe<T> Nothing() {
        return Maybe<T>{};
    }

    template<class T>
    struct Show<Maybe<T>> {
        static std::string show(Maybe<T> const &value) {
            if (value.has_value()) {
                return std::string{"Just "} + Show<T>::show(value.value());
            }
            return std::string{"Nothing"};
        }
    };

    template<>
    struct Functor<Maybe> {
        template<class Func, class A>
        static auto map(
                Func const &func,
                Maybe<A> const &a
        ) {
            using B = decltype(func(a.value()));
            if (a.has_value())
                return Just<B>(func(a.value()));
            return Nothing<B>();
        }
    };

    template<class T>
    struct Semigroup<Maybe<T>> {
        static Maybe<T> append(Maybe<T> const &a, Maybe<T> const &b) {
            if (a.has_value() && b.has_value())
                return Just<T>(Semigroup<T>::append(a.value(), b.value()));
            return Nothing<T>();
        }
    };

    template<class T>
    struct Monoid<Maybe<T>> {
        static Maybe<T> mempty() {
            return Nothing<T>();
        }
    };

    template<>
    struct Apply<Maybe> {
        template<class Func, class A>
        static auto apply1(
                Maybe<Func> const &func,
                Maybe<A> const &a
        ) {
            using B = decltype(func.value()(a.value()));
            if (func.has_value() && a.has_value()) {
                return Just<B>(func.value()(a.value()));
            }
            return Nothing<B>();
        }
    };

    template<>
    struct Applicative<Maybe> {
        template<class T>
        static Maybe<T> pure(T &&value) {
            return Just<T>(std::forward(value));
        }
    };

    template<>
    struct Bind<Maybe> {
        template<class Func, class A>
        static auto bind1(
                Maybe<A> const &a,
                Func const &func
        ) {
            using B = decltype(func(a.value()));
            if (a.has_value())
                return func(a.value());
            return B{};
        }
    };


NAMESPACE_END(MONAD)


#endif //RABENDALIB_MAYBE_HPP
