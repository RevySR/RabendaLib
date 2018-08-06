#ifndef RABENDALIB_REFLECTION_OBJECT
#define RABENDALIB_REFLECTION_OBJECT



#include <rabenda/lib_common.hpp>
#include <rabenda/basic/RString.hpp>

NAMESPACE_BEGIN(reflection)
using namespace NAMESPACE_GET(basic);
struct RObject
{
public:
	RObject();
	virtual ~RObject();

	static RString<> GetName() noexcept
	{
		return "RObject"_rs;
	}


};

NAMESPACE_END(reflection)

#endif

