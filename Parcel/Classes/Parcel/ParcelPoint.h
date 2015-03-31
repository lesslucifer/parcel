//
//  Json.h
//  Parcel
//
//  Created by Vinova on 3/30/15.
//
//

#ifndef Parcel_Json_h
#define Parcel_Json_h
#pragma once

#include "Parcel.h"
#include "jsonserialization.h"
#include "ParcelFloat.h"
#include "ParcelShortcut.h"
#include "cocos2d.h"

namespace parcel {
    __PARCEL_TEMPLATE class Parcel<Json::Value, cocos2d::Point>
    {
    private:
        cocos2d::Point p;
    public:
        Parcel<>(const Json::Value &v)
        {
            p = cocos2d::Point::ZERO;
            if (v.type() == Json::ValueType::objectValue)
            {
                if (v.isMember("x"))
                {
                    p.x = Parcel<Json::Value, float>(v["x"]).get();
                    p.y = Parcel<Json::Value, float>(v["y"]).get();
                }
            }
            else if (v.type() == Json::ValueType::stringValue)
            {
                // init as string shortcut
                Parcel<Json::Value, ParcelShortcut> shortcut(v);
                if (shortcut.get().getTypeID() == "#p")   // or #P
                {
                    p.x = shortcut.get().getData<float>(0).get();
                    p.y = shortcut.get().getData<float>(1).get();
                }
            }
            
            // throw exception
        }
        
        const cocos2d::Point& get(cocos2d::Point *p) const
        {
            if (p == nullptr)
                return get();
            
            (*p) = this->p;
            return *p;
        }
        
        const cocos2d::Point& get() const
        {
            return this->p;
        }
    };
}

#endif
