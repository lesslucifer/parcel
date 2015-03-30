#ifndef __JSONSER_TYPE_SERIALIZOR_H__
#define __JSONSER_TYPE_SERIALIZOR_H__

#include "def.hpp"
#include <string>

using std::string;

#ifdef __GNUC__
#define __JSONSER_TEMPLATE template<>
#else
#define __JSONSER_TEMPLATE 
#endif // __GNUC__

#define JSONCPP_DEFINE(...) \
	inline Json::Value serialize() const \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).serialize(); \
	} \
	\
	inline bool deserialize(const Json::Value& j) \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).deserialize(j); \
	}

#define JSONCPP_STATIC_DEFINE(...) \
	inline static Json::Value serialize() \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).serialize(); \
	} \
	\
	inline static bool deserialize(const Json::Value& j) \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).deserialize(j); \
	}

#define JSONCPP_DEFINE_NEW_TYPE(TYPE, FACE, ...) \
	__JSONSER_TEMPLATE inline Json::Value serialize(const TYPE &FACE) \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).serialize(); \
	} \
	\
	__JSONSER_TEMPLATE inline bool deserialize(const Json::Value& j, TYPE &FACE) \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).deserialize(j); \
	}

namespace Json {
	namespace type
	{

#ifdef __GNUC__
		template <typename V>
		inline bool deserialize(const Json::Value &j, typename std::map<std::string, V> &v);
		template <typename V>
		inline Json::Value serialize(typename std::map<std::string, V> const &v);

		template <typename K, typename V>
		inline bool deserialize(const Json::Value &j, typename std::map<K, V> &v);
		template <typename K, typename V>
		inline Json::Value serialize(typename std::map<K, V> const &v);

		template <typename V>
		inline bool deserialize(const Json::Value &j, typename std::vector<V> &v);
		template <typename V>
		inline Json::Value serialize( typename std::vector<V> const &v);

		template <typename V>
		inline bool deserialize(const Json::Value &j, V &v);
		template <typename V>
		inline Json::Value serialize(const V &v);
#endif

		template<typename A0 = void, typename A1 = void, typename A2 = void, typename A3 = void, typename A4 = void, typename A5 = void, typename A6 = void, typename A7 = void, typename A8 = void, typename A9 = void, typename A10 = void>
struct serializor;

template<typename A0>
struct serializor<A0> {

    serializor(const char *_k0, A0 &_a0) :
    k0(_k0), a0(_a0) {
    }

    bool deserialize(const Json::Value &j) {
        bool ret = true;
        ret = ret && Json::type::deserialize(j[k0], a0);
        return true;
    }

    Json::Value serialize() const {
        Json::Value jVal;
        jVal[k0] = Json::type::serialize(a0);
        return jVal;
    }

    const char *k0;
    A0 &a0;
};

template<typename A0, typename A1>
struct serializor<A0, A1> {

    serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1) :
    k0(_k0), a0(_a0), k1(_k1), a1(_a1) {
    }

    bool deserialize(const Json::Value &j) {
        bool ret = true;
        ret = ret && Json::type::deserialize(j[k0], a0);
        ret = ret && Json::type::deserialize(j[k1], a1);
        return true;
    }

    Json::Value serialize() const {
        Json::Value jVal;
        jVal[k0] = Json::type::serialize(a0);
        jVal[k1] = Json::type::serialize(a1);
        return jVal;
    }

    const char *k0;
    A0 &a0;
    const char *k1;
    A1 &a1;
};

template<typename A0, typename A1, typename A2>
struct serializor<A0, A1, A2> {

    serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2) :
    k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2) {
    }

    bool deserialize(const Json::Value &j) {
        bool ret = true;
        ret = ret && Json::type::deserialize(j[k0], a0);
        ret = ret && Json::type::deserialize(j[k1], a1);
        ret = ret && Json::type::deserialize(j[k2], a2);
        return true;
    }

    Json::Value serialize() const {
        Json::Value jVal;
        jVal[k0] = Json::type::serialize(a0);
        jVal[k1] = Json::type::serialize(a1);
        jVal[k2] = Json::type::serialize(a2);
        return jVal;
    }

    const char *k0;
    A0 &a0;
    const char *k1;
    A1 &a1;
    const char *k2;
    A2 &a2;
};

template<typename A0, typename A1, typename A2, typename A3>
struct serializor<A0, A1, A2, A3> {

    serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3) :
    k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3) {
    }

    bool deserialize(const Json::Value &j) {
        bool ret = true;
        ret = ret && Json::type::deserialize(j[k0], a0);
        ret = ret && Json::type::deserialize(j[k1], a1);
        ret = ret && Json::type::deserialize(j[k2], a2);
        ret = ret && Json::type::deserialize(j[k3], a3);
        return true;
    }

    Json::Value serialize() const {
        Json::Value jVal;
        jVal[k0] = Json::type::serialize(a0);
        jVal[k1] = Json::type::serialize(a1);
        jVal[k2] = Json::type::serialize(a2);
        jVal[k3] = Json::type::serialize(a3);
        return jVal;
    }

    const char *k0;
    A0 &a0;
    const char *k1;
    A1 &a1;
    const char *k2;
    A2 &a2;
    const char *k3;
    A3 &a3;
};

template<typename A0, typename A1, typename A2, typename A3, typename A4>
struct serializor<A0, A1, A2, A3, A4> {

    serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4) :
    k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4) {
    }

    bool deserialize(const Json::Value &j) {
        bool ret = true;
        ret = ret && Json::type::deserialize(j[k0], a0);
        ret = ret && Json::type::deserialize(j[k1], a1);
        ret = ret && Json::type::deserialize(j[k2], a2);
        ret = ret && Json::type::deserialize(j[k3], a3);
        ret = ret && Json::type::deserialize(j[k4], a4);
        return true;
    }

    Json::Value serialize() const {
        Json::Value jVal;
        jVal[k0] = Json::type::serialize(a0);
        jVal[k1] = Json::type::serialize(a1);
        jVal[k2] = Json::type::serialize(a2);
        jVal[k3] = Json::type::serialize(a3);
        jVal[k4] = Json::type::serialize(a4);
        return jVal;
    }

    const char *k0;
    A0 &a0;
    const char *k1;
    A1 &a1;
    const char *k2;
    A2 &a2;
    const char *k3;
    A3 &a3;
    const char *k4;
    A4 &a4;
};

template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
struct serializor<A0, A1, A2, A3, A4, A5> {

    serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5) :
    k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5) {
    }

    bool deserialize(const Json::Value &j) {
        bool ret = true;
        ret = ret && Json::type::deserialize(j[k0], a0);
        ret = ret && Json::type::deserialize(j[k1], a1);
        ret = ret && Json::type::deserialize(j[k2], a2);
        ret = ret && Json::type::deserialize(j[k3], a3);
        ret = ret && Json::type::deserialize(j[k4], a4);
        ret = ret && Json::type::deserialize(j[k5], a5);
        return true;
    }

    Json::Value serialize() const {
        Json::Value jVal;
        jVal[k0] = Json::type::serialize(a0);
        jVal[k1] = Json::type::serialize(a1);
        jVal[k2] = Json::type::serialize(a2);
        jVal[k3] = Json::type::serialize(a3);
        jVal[k4] = Json::type::serialize(a4);
        jVal[k5] = Json::type::serialize(a5);
        return jVal;
    }

    const char *k0;
    A0 &a0;
    const char *k1;
    A1 &a1;
    const char *k2;
    A2 &a2;
    const char *k3;
    A3 &a3;
    const char *k4;
    A4 &a4;
    const char *k5;
    A5 &a5;
};

template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
struct serializor<A0, A1, A2, A3, A4, A5, A6> {

    serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6) :
    k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6) {
    }

    bool deserialize(const Json::Value &j) {
        bool ret = true;
        ret = ret && Json::type::deserialize(j[k0], a0);
        ret = ret && Json::type::deserialize(j[k1], a1);
        ret = ret && Json::type::deserialize(j[k2], a2);
        ret = ret && Json::type::deserialize(j[k3], a3);
        ret = ret && Json::type::deserialize(j[k4], a4);
        ret = ret && Json::type::deserialize(j[k5], a5);
        ret = ret && Json::type::deserialize(j[k6], a6);
        return true;
    }

    Json::Value serialize() const {
        Json::Value jVal;
        jVal[k0] = Json::type::serialize(a0);
        jVal[k1] = Json::type::serialize(a1);
        jVal[k2] = Json::type::serialize(a2);
        jVal[k3] = Json::type::serialize(a3);
        jVal[k4] = Json::type::serialize(a4);
        jVal[k5] = Json::type::serialize(a5);
        jVal[k6] = Json::type::serialize(a6);
        return jVal;
    }

    const char *k0;
    A0 &a0;
    const char *k1;
    A1 &a1;
    const char *k2;
    A2 &a2;
    const char *k3;
    A3 &a3;
    const char *k4;
    A4 &a4;
    const char *k5;
    A5 &a5;
    const char *k6;
    A6 &a6;
};

template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
struct serializor<A0, A1, A2, A3, A4, A5, A6, A7> {

    serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7) :
    k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7) {
    }

    bool deserialize(const Json::Value &j) {
        bool ret = true;
        ret = ret && Json::type::deserialize(j[k0], a0);
        ret = ret && Json::type::deserialize(j[k1], a1);
        ret = ret && Json::type::deserialize(j[k2], a2);
        ret = ret && Json::type::deserialize(j[k3], a3);
        ret = ret && Json::type::deserialize(j[k4], a4);
        ret = ret && Json::type::deserialize(j[k5], a5);
        ret = ret && Json::type::deserialize(j[k6], a6);
        ret = ret && Json::type::deserialize(j[k7], a7);
        return true;
    }

    Json::Value serialize() const {
        Json::Value jVal;
        jVal[k0] = Json::type::serialize(a0);
        jVal[k1] = Json::type::serialize(a1);
        jVal[k2] = Json::type::serialize(a2);
        jVal[k3] = Json::type::serialize(a3);
        jVal[k4] = Json::type::serialize(a4);
        jVal[k5] = Json::type::serialize(a5);
        jVal[k6] = Json::type::serialize(a6);
        jVal[k7] = Json::type::serialize(a7);
        return jVal;
    }

    const char *k0;
    A0 &a0;
    const char *k1;
    A1 &a1;
    const char *k2;
    A2 &a2;
    const char *k3;
    A3 &a3;
    const char *k4;
    A4 &a4;
    const char *k5;
    A5 &a5;
    const char *k6;
    A6 &a6;
    const char *k7;
    A7 &a7;
};

template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8> {

    serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8) :
    k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8) {
    }

    bool deserialize(const Json::Value &j) {
        bool ret = true;
        ret = ret && Json::type::deserialize(j[k0], a0);
        ret = ret && Json::type::deserialize(j[k1], a1);
        ret = ret && Json::type::deserialize(j[k2], a2);
        ret = ret && Json::type::deserialize(j[k3], a3);
        ret = ret && Json::type::deserialize(j[k4], a4);
        ret = ret && Json::type::deserialize(j[k5], a5);
        ret = ret && Json::type::deserialize(j[k6], a6);
        ret = ret && Json::type::deserialize(j[k7], a7);
        ret = ret && Json::type::deserialize(j[k8], a8);
        return true;
    }

    Json::Value serialize() const {
        Json::Value jVal;
        jVal[k0] = Json::type::serialize(a0);
        jVal[k1] = Json::type::serialize(a1);
        jVal[k2] = Json::type::serialize(a2);
        jVal[k3] = Json::type::serialize(a3);
        jVal[k4] = Json::type::serialize(a4);
        jVal[k5] = Json::type::serialize(a5);
        jVal[k6] = Json::type::serialize(a6);
        jVal[k7] = Json::type::serialize(a7);
        jVal[k8] = Json::type::serialize(a8);
        return jVal;
    }

    const char *k0;
    A0 &a0;
    const char *k1;
    A1 &a1;
    const char *k2;
    A2 &a2;
    const char *k3;
    A3 &a3;
    const char *k4;
    A4 &a4;
    const char *k5;
    A5 &a5;
    const char *k6;
    A6 &a6;
    const char *k7;
    A7 &a7;
    const char *k8;
    A8 &a8;
};

template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9> {

    serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9) :
    k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9) {
    }

    bool deserialize(const Json::Value &j) {
        bool ret = true;
        ret = ret && Json::type::deserialize(j[k0], a0);
        ret = ret && Json::type::deserialize(j[k1], a1);
        ret = ret && Json::type::deserialize(j[k2], a2);
        ret = ret && Json::type::deserialize(j[k3], a3);
        ret = ret && Json::type::deserialize(j[k4], a4);
        ret = ret && Json::type::deserialize(j[k5], a5);
        ret = ret && Json::type::deserialize(j[k6], a6);
        ret = ret && Json::type::deserialize(j[k7], a7);
        ret = ret && Json::type::deserialize(j[k8], a8);
        ret = ret && Json::type::deserialize(j[k9], a9);
        return true;
    }

    Json::Value serialize() const {
        Json::Value jVal;
        jVal[k0] = Json::type::serialize(a0);
        jVal[k1] = Json::type::serialize(a1);
        jVal[k2] = Json::type::serialize(a2);
        jVal[k3] = Json::type::serialize(a3);
        jVal[k4] = Json::type::serialize(a4);
        jVal[k5] = Json::type::serialize(a5);
        jVal[k6] = Json::type::serialize(a6);
        jVal[k7] = Json::type::serialize(a7);
        jVal[k8] = Json::type::serialize(a8);
        jVal[k9] = Json::type::serialize(a9);
        return jVal;
    }

    const char *k0;
    A0 &a0;
    const char *k1;
    A1 &a1;
    const char *k2;
    A2 &a2;
    const char *k3;
    A3 &a3;
    const char *k4;
    A4 &a4;
    const char *k5;
    A5 &a5;
    const char *k6;
    A6 &a6;
    const char *k7;
    A7 &a7;
    const char *k8;
    A8 &a8;
    const char *k9;
    A9 &a9;
};

template <typename A0>
serializor<A0> make_serializor(const char *k0, A0 &a0) {
    return serializor<A0>(k0, a0);
}

template <typename A0, typename A1>
serializor<A0, A1> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1) {
    return serializor<A0, A1>(k0, a0, k1, a1);
}

template <typename A0, typename A1, typename A2>
serializor<A0, A1, A2> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2) {
    return serializor<A0, A1, A2>(k0, a0, k1, a1, k2, a2);
}

template <typename A0, typename A1, typename A2, typename A3>
serializor<A0, A1, A2, A3> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3) {
    return serializor<A0, A1, A2, A3>(k0, a0, k1, a1, k2, a2, k3, a3);
}

template <typename A0, typename A1, typename A2, typename A3, typename A4>
serializor<A0, A1, A2, A3, A4> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4) {
    return serializor<A0, A1, A2, A3, A4>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4);
}

template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
serializor<A0, A1, A2, A3, A4, A5> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5) {
    return serializor<A0, A1, A2, A3, A4, A5>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5);
}

template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
serializor<A0, A1, A2, A3, A4, A5, A6> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6) {
    return serializor<A0, A1, A2, A3, A4, A5, A6>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6);
}

template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
serializor<A0, A1, A2, A3, A4, A5, A6, A7> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7) {
    return serializor<A0, A1, A2, A3, A4, A5, A6, A7>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7);
}

template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8) {
    return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8);
}

template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9) {
    return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9);
}
	}	// namespace type
}  // namespace Json

#endif
