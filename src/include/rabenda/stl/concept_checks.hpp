//
// Created by Rabenda on 09/07/2017.
//

#ifndef RABENDALIB_CONCEPT_CHECKS_HPP
#define RABENDALIB_CONCEPT_CHECKS_HPP

#include "stl_config.hpp"

NAMESPACE_BEGIN(stl)

#ifndef __STL_USE_CONCEPT_CHECKS
#define __STL_REQUIRES(__type_var, __concept) do {} while(0)
#else
#define __STL_REQUIRES(__type_var, __concept)
#endif

NAMESPACE_END(stl)

#endif //RABENDALIB_CONCEPT_CHECKS_HPP
