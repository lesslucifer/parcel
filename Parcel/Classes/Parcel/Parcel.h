//
//  Parcel.h
//  Parcel
//
//  Created by Vinova on 3/30/15.
//
//

#ifndef __Parcel__Parcel__
#define __Parcel__Parcel__
#pragma once

#include <stdio.h>
#include <string>

namespace parcel {
#ifndef __PARCEL_UNICODE
    typedef char tchar;
    typedef std::string tstring;
#else
    typedef wchar_t tchar;
    typedef std::wstring tstring;
#endif
    
#ifdef __GNUC__
#define __PARCEL_TEMPLATE template<>
#else
#define __PARCEL_TEMPLATE
#endif // __GNUC__
    
    template <typename __T_IN = void>
    class CloneableParcel
    {
    public:
        virtual CloneableParcel* clone() = 0;
    };
    
    template <typename __T_IN = void, typename __T_OUT = void>
    class Parcel : CloneableParcel<__T_IN>
    {
    public:
        Parcel<>(const __T_IN &inp);
        const __T_OUT& get(__T_OUT *outp) const;
        const __T_OUT& get() const;
        
        CloneableParcel<__T_IN>* clone()
        {
            return nullptr;
        }
    };
}

#endif /* defined(__Parcel__Parcel__) */
