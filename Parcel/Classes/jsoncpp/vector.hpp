#ifndef __JSONSER_TYPE_VECTOR_H__
#define __JSONSER_TYPE_VECTOR_H__

#include "def.hpp"
#include <vector>

namespace Json {
	namespace type
	{
		template <typename V>
		inline bool deserialize(const Json::Value &j, typename std::vector<V> &v)
		{
			v.clear();
			if (j.isArray())
			{
				v.reserve(j.size());
				for (unsigned int i = 0; i < j.size(); ++i)
				{
					V val;
					Json::type::deserialize(j[i], val);
					v.push_back(val);
				}
				return true;
			}

			return false;
		}

		template <typename V>
		inline Json::Value serialize(typename std::vector<V> const &v)
		{
			Json::Value jVal;
			for (unsigned int i = 0; i < v.size(); ++i)
			{
				jVal.append(Json::type::serialize(v[i]));
			}

			return jVal;
		}
	}
}  // namespace Json

#endif
