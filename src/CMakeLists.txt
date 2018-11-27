PROJECT(rabendalib)
INCLUDE_DIRECTORIES(
	include
)

SET(SOURCE_FILES
	include/rabenda/lib_common.hpp
		include/rabenda/basic/RString.hpp
	include/rabenda/monad/Class/Applicative.hpp
	include/rabenda/monad/Class/Apply.hpp
	include/rabenda/monad/Class/Bind.hpp
	include/rabenda/monad/Class/Foldable.hpp
	include/rabenda/monad/Class/Functor.hpp
	include/rabenda/monad/Class/Monoid.hpp
	include/rabenda/monad/Class/Semigroup.hpp
	include/rabenda/monad/Class/Show.hpp
	include/rabenda/monad/Data/Maybe.hpp
		include/rabenda/reflection/robject.hpp
	include/rabenda/stl/concept_checks.hpp
	include/rabenda/stl/defalloc.hpp
	include/rabenda/stl/stl_algobase.hpp
	include/rabenda/stl/stl_alloc.hpp
	include/rabenda/stl/stl_config.hpp
	include/rabenda/stl/stl_construct.hpp
	include/rabenda/stl/stl_function.hpp
	include/rabenda/stl/stl_iterator.hpp
	include/rabenda/stl/stl_iterator_base.hpp
	include/rabenda/stl/stl_numeric.hpp
	include/rabenda/stl/stl_pair.hpp
	include/rabenda/stl/stl_uninitialized.hpp
	include/rabenda/stl/type_traits.hpp
	)


ADD_LIBRARY(${PROJECT_NAME} STATIC ${SOURCE_FILES} empty.cpp)
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)