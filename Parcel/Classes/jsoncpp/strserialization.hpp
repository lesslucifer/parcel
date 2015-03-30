#ifndef __JSONSER_STR_H__
#define __JSONSER_STR_H__

#include "def.hpp"

namespace Json {
	namespace type
	{
		template <typename V>
		inline std::string strSerialize(const V &v);
		template <typename V>
		inline bool strDeserialize(const std::string &s, V &v);
	}
}  // namespace Json

#endif
