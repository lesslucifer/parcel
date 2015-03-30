#ifndef __JSONSER_TYPE_INT_H__
#define __JSONSER_TYPE_INT_H__

#include "def.hpp"

namespace Json {
	namespace type
	{
#ifdef __GNUC__
#define __JSONSER_TEMPLATE template<>
#else
#define __JSONSER_TEMPLATE 
#endif // __GNUC__
		__JSONSER_TEMPLATE inline bool deserialize(const Json::Value &j, int &v)
		{
			if (j.isNumeric())
			{
				v = j.asInt();
				return true;
			}

			return false;
		}

		__JSONSER_TEMPLATE inline Json::Value serialize(const int &v)
		{
			return Json::Value(v);
		}
	}
}  // namespace Json

#endif
