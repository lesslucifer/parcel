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

#include "Parcel.hpp"
#include "jsonserialization.h"
#include "Float.h"
#include "Shortcut.h"
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
                    p.x = Parcel<Json::Value, float>(v["x"]).get(nullptr);
                    p.y = Parcel<Json::Value, float>(v["y"]).get(nullptr);
                }
            }
            else if (v.type() == Json::ValueType::stringValue)
            {
                // init as string shortcut
                Parcel<Json::Value, ParcelShortcut> shortcut(v);
                if (shortcut.get(nullptr).getTypeID() == "p")   // or P
                {
                    p.x = shortcut.get(nullptr).getData<float>(0).get(nullptr);
                    p.y = shortcut.get(nullptr).getData<float>(1).get(nullptr);
                }
            }
            
            // throw exception
        }
        
        const cocos2d::Point& get(cocos2d::Point *p)
        {
            if (p != nullptr)
            {
                (*p) = this->p;
                return *p;
            }
            
            return this->p;
        }
    };
}

#endif
