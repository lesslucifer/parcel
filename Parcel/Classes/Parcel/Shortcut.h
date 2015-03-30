//
//  Shortcut.h
//  Parcel
//
//  Created by Vinova on 3/30/15.
//
//

#ifndef Parcel_Shortcut_h
#define Parcel_Shortcut_h

#pragma once

#include "Parcel.hpp"
#include "jsonserialization.h"
#include <string>
#include <vector>

namespace parcel {
    
    class
    struct ParcelShortcut
    {
    private:
        std::string typeId;
        std::vector<std::string> data;
        
    public:
        const std::string& getTypeID()
        {
            return this->typeId;
        }
        
        const std::string& operator[](const unsigned int &idx)
        {
            return this->data[idx];
        }
        
        template<typename T>
        Parcel<Json::Value, T> getData(const unsigned int &idx)
        {
            auto &s = data[idx];
            auto json = Json::Value(s);
            
            return Parcel<Json::Value, T>(json);
        }
        
        friend class Parcel<Json::Value, ParcelShortcut>;
    };
    
    __PARCEL_TEMPLATE class Parcel<Json::Value, ParcelShortcut>
    {
    private:
        ParcelShortcut shortcut;
    public:
        Parcel<>(const Json::Value &v)
        {
            // throw exceptions
            if (v.isString())
            {
                
            }
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
