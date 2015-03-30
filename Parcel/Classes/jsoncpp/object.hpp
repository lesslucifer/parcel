#ifndef __JSONSER_TYPE_OBJECT_H__
#define __JSONSER_TYPE_OBJECT_H__

#include "def.hpp"

namespace Json {
	namespace type
	{
		template <class O>
		inline bool deserialize(const Json::Value &j, O &v)
		{
			return v.deserialize(j);
		}

		template <class O>
		inline Json::Value serialize(const O &v)
		{
			return v.serialize();
		}
	}
}  // namespace Json

#endif
