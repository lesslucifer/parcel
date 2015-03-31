//
//  ParcelJsonParser.h
//  Parcel
//
//  Created by Vinova on 3/31/15.
//
//

#ifndef Parcel_ParcelJsonParser_h
#define Parcel_ParcelJsonParser_h

#pragma once

#include "ParcelParser.h"
#include "jsonserialization.h"
#include <unordered_map>

namespace parcel {
    using JsonParser = Parser<Json::Value>;
    
    __PARCEL_TEMPLATE class Parser<Json::Value>
    {
    private:
        
    public:
        CloneableParcel<Json::Value>* parse(const Json::Value &inp)
        {
            return nullptr;
        }
    };
}

#endif
