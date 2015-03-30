#ifndef __JSONSER_TYPE_BOOL_H__
#define __JSONSER_TYPE_BOOL_H__

#include "def.hpp"

namespace Json {
	namespace type
	{
#ifdef __GNUC__
#define __JSONSER_TEMPLATE template<>
#else
#define __JSONSER_TEMPLATE 
#endif // __GNUC__
		__JSONSER_TEMPLATE inline bool deserialize(const Value &j, bool &v)
		{
			if (j.isBool())
			{
				v = j.asBool();
				return true;
			}

			return false;
		}

		__JSONSER_TEMPLATE inline Value serialize(const bool &v)
		{
			return Json::Value(v);
		}
	}
}  // namespace Json

#endif
