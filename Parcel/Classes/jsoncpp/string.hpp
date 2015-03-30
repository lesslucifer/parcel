#ifndef __JSONSER_TYPE_STRING_H__
#define __JSONSER_TYPE_STRING_H__

#include "def.hpp"
#include <string>

namespace Json {
	namespace type
	{
#ifdef __GNUC__
#define __JSONSER_TEMPLATE template<>
#else
#define __JSONSER_TEMPLATE 
#endif // __GNUC__
		__JSONSER_TEMPLATE inline bool deserialize(const Json::Value &j, std::string &v)
		{
			if (j.isString())
			{
				v = j.asString();
				return true;
			}

			return false;
		}

		__JSONSER_TEMPLATE inline Json::Value serialize(const std::string &v)
		{
			return Json::Value(v);
		}
	}
}  // namespace Json

#endif
