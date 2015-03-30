#ifndef __JSONSER_TYPE_JSON_VALUE_H__
#define __JSONSER_TYPE_JSON_VALUE_H__

#include "def.hpp"

namespace Json {
	namespace type
	{
#ifdef __GNUC__
#define __JSONSER_TEMPLATE template<>
#else
#define __JSONSER_TEMPLATE 
#endif // __GNUC__
		__JSONSER_TEMPLATE inline bool deserialize(const Json::Value &j, Json::Value &v)
		{
			v = Json::Value(j);
			return true;
		}

		__JSONSER_TEMPLATE inline Json::Value serialize(const Json::Value &v)
		{
			return Json::Value(v);
		}
	}
}  // namespace Json

#endif
