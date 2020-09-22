//
//  set.hpp
//  Pratice unn 2020
//
//  Created by Huncho on 19/09/2020.
//  Copyright © 2020 TIERE. All rights reserved.
//

#ifndef set_hpp
#define set_hpp

#include "bitfield.h"
class Tset{
private :
    int maxPower ;
    TBitField Bitfield;
public:
    Tset(int mp);
    Tset(const Tset &s);
    Tset(const TBitField &bf);
    operator TBitField();
    //
    int GetMaxPower (void) const;
    void InsElem(const int n);
    void DelElem(const int n);
    int isMember(const int n) const;
    //
    int operator == (const Tset &s);
    Tset &operator = (const Tset &s);
    Tset operator + (const int n);
    Tset operator - (const int n);
    Tset operator + (const Tset &s);
    Tset operator * (const Tset &s);
    Tset operator ~ (void);
    friend std::istream &operator>>(std::istream &istr, Tset &bf);
    friend std::ostream &operator<<(std::ostream &ostr, const Tset &bf);
    
};

#endif /* set_hpp */
