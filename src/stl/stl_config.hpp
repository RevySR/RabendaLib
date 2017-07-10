#ifndef RABENDALIB_STL_CONFIG
#define RABENDALIB_STL_CONFIG

#include "../config.h"

#define PURE_STL

#ifdef PURE_STL

#include <cstddef>
#include <cstring>
#include <new>
#include <iostream>
using std::memcmp;
using std::memmove;
using std::set_new_handler;
using std::cerr;
using std::endl;
#else
using ptrdiff_t = int;
using size_t = unsigned;
#endif


#define __STL_USE_NAMESPACES
#define __STL_CLASS_PARTIAL_SPECIALIZATION
#define __STL_USE_EXCEPTIONS

//!定义 STL是否使用异常
#ifdef __STL_USE_EXCEPTIONS
#define __STL_TRY try
#define __STL_CATCH_ALL catch(...)
#define __STL_THROW(x) throw x
#define __STL_RETHROW throw
#define __STL_NOTHROW noexcept
#define __STL_UNWIND(action) catch(...) {action; throw;}
#else
#define __STL_TRY
#define __STL_CATCH_ALL if(false)
#define __STL_THROW(x)
#define __STL_RETHROW
#define __STL_NOTHROW
#define __STL_UNWIND(action)
#endif


#endif //RABENDALIB_STL_CONFIG
