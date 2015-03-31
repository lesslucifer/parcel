//
//  ParcelParser.h
//  Parcel
//
//  Created by Vinova on 3/31/15.
//
//

#ifndef Parcel_ParcelParser_h
#define Parcel_ParcelParser_h
#pragma once

#include "Parcel.h"
#include <list>
#include <memory>

namespace parcel {
    template<typename __T_IN = void>
    class ParcelFactory
    {
        bool isAccept(const __T_IN &inp) const;
        std::shared_ptr<CloneableParcel<__T_IN>> make(const __T_IN &inp) const;
    };
    
    template<typename __T_IN>
    class Parser
    {
    private:
        std::list<ParcelFactory<__T_IN>> factories;
        
    public:
        CloneableParcel<__T_IN>* parse(const __T_IN &inp)
        {
            for (auto &fact : factories)
            {
                if (fact.isAccept(inp))
                {
                    return fact.make(inp);
                }
            }
        }
    };
}

#endif
