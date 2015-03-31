//
//  PacelJson.h
//  Parcel
//
//  Created by Vinova on 3/31/15.
//
//

#ifndef Parcel_PacelJson_h
#define Parcel_PacelJson_h
#pragma once

#include "Parcel.h"
#include "jsonserialization.h"

namespace parcel {
    typedef parcel::CloneableParcel<Json::Value> CloneableJsonParcel;
    
    template <typename __T_OUT = void>
    using JsonParcel = parcel::Parcel<Json::Value, __T_OUT>;
}

#endif