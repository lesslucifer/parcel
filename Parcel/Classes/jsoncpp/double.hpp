#ifndef __JSONSER_TYPE_DOUBLE_H__
#define __JSONSER_TYPE_DOUBLE_H__

#include "def.hpp"

namespace Json {
	namespace type
	{
#ifdef __GNUC__
#define __JSONSER_TEMPLATE template<>
#else
#define __JSONSER_TEMPLATE 
#endif // __GNUC__
		__JSONSER_TEMPLATE inline bool deserialize(const Json::Value &j, double &v)
		{
			if (j.isNumeric())
			{
				v = j.asDouble();
				return true;
			}

			return false;
		}

		__JSONSER_TEMPLATE inline Json::Value serialize(const double &v)
		{
			return Json::Value(v);
		}
	}
}  // namespace Json

#endif
