#ifndef __JSONSER_TYPE_OBJECT_STR_H__
#define __JSONSER_TYPE_OBJECT_STR_H__

#include "def.hpp"

#define JSONCPP_STR_DEFINE_NEW_TYPE(CLASS) \
		template <> inline bool strDeserialize(const std::string &s, CLASS &v) \
		{ \
			Json::Reader reader; \
			Json::Value j; \
			reader.parse(s, j, false); \
			return Json::type::deserialize(j, v); \
		} \
		\
		template <> inline std::string strSerialize(const CLASS &v) \
		{ \
			Json::Value j = Json::type::serialize(v); \
			Json::FastWriter writer; \
			return writer.write(j); \
		}

#endif
