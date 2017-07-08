#ifndef RABENDALIB_STL_CONFIG
#define RABENDALIB_STL_CONFIG
#include "../config.h"

#define PURE_STL

#ifdef PURE_STL
#include <cstddef>
#include <cstring>
using std::memcmp;
using std::memmove;
#else
using ptrdiff_t = int;
using size_t = unsigned;
#endif

#endif //RABENDALIB_STL_CONFIG
