//
//  Float.h
//  Parcel
//
//  Created by Vinova on 3/30/15.
//
//

#ifndef Parcel_Float_h
#define Parcel_Float_h

#pragma once

#include "Parcel.hpp"
#include "jsonserialization.h"
#include <string>

namespace parcel {
    __PARCEL_TEMPLATE class Parcel<Json::Value, float>
    {
    private:
        float value;
    public:
        Parcel<>(const Json::Value &v)
        {
            value = 0.f;
            switch (v.type()) {
                case Json::ValueType::intValue:
                    value = v.asInt();
                    break;
                case Json::ValueType::uintValue:
                    value = v.asUInt();
                    break;
                case Json::ValueType::realValue:
                    value = v.asFloat();
                    break;
                case Json::ValueType::stringValue:
                    value = std::stof(v.asString());
                    break;
                default:
                    break;
            };
            
            // throw exceptions
        }
        
        const float& get(float *f)
        {
            if (f != nullptr)
            {
                (*f) = this->value;
                return *f;
            }
            
            return this->value;
        }
    };
}

#endif
