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

#include "ParcelJson.h"
#include <string>
#include <vector>

namespace parcel {
    
    struct ParcelShortcut
    {
    private:
        std::string typeId;
        std::vector<std::string> data;
        
    public:
        const std::string& getTypeID() const
        {
            return this->typeId;
        }
        
        const std::string& operator[](const unsigned int &idx) const
        {
            return this->data[idx];
        }
        
        template<typename T>
        Parcel<Json::Value, T> getData(const unsigned int &idx) const
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
            if (!v.isString())
            {
                // throw exceptions
                return;
            }
            
            string s = v.asString();
            if (s.length() <= 0 || s[0] != '#')
                return; // throw exceptions;
            
            size_t pos = 1;
            char delim = '_';
            bool hastypeID = false;
            auto push = [&](const string &str)
            {
                if (!hastypeID)
                {
                    std::transform(str.begin(), str.end(), shortcut.typeId.begin(), ::tolower);
                    hastypeID = true;
                }
                else
                {
                    shortcut.data.push_back(str);
                }
            };
            
            while ((pos = s.find(delim, pos)) != std::string::npos)
            {
                string ss = s.substr(0, pos);
                push(ss);
                
                s.erase(0, pos + 1);
            }
            push(s);
        }
        
        const ParcelShortcut& get(ParcelShortcut *sh) const
        {
            if (sh == nullptr)
                return get();
            
            *sh = this->shortcut;
            return *sh;
        }
        
        const ParcelShortcut& get() const
        {
            return this->shortcut;
        }
    };
}

#endif
