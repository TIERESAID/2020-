//
//  set.cpp
//  Pratice unn 2020
//
//  Created by Huncho on 19/09/2020.
//  Copyright © 2020 TIERE. All rights reserved.
//

#include "set.h"

Tset :: Tset(int mp): maxPower(mp), Bitfield(mp) {}

Tset :: Tset (const Tset &s) : maxPower(s.maxPower),Bitfield(s.Bitfield){}

Tset :: Tset (const TBitField &bf) : maxPower(bf.Getlength()),Bitfield(bf){}


Tset :: operator TBitField () {
    TBitField temp (this->Bitfield);
    return temp;
}

int Tset :: GetMaxPower(void) const  {
    return maxPower;
}
//

int Tset :: isMember(const int Elem) const{
    return Bitfield.GetBit(Elem);
}

void Tset :: InsElem(const int Elem){
    Bitfield.SetBit(Elem);
}

void Tset :: DelElem(const int Elem){
    Bitfield.ClrBit(Elem);
}

Tset & Tset :: operator=(const Tset &s){
    Bitfield = s.Bitfield;
    maxPower = s.GetMaxPower();
    return *this;
}
//

int Tset :: operator==(const Tset &s){
    
    return Bitfield == s.Bitfield;
}

Tset  Tset :: operator+ (const Tset &s){
    Tset temp(Bitfield | s.Bitfield);
    return temp;
}
//

Tset  Tset :: operator* (const Tset &s){
    Tset temp(Bitfield & s.Bitfield);
    return temp;
}


Tset  Tset :: operator~(void){
    Tset temp(~Bitfield);
    return temp;
}
//

std::istream &operator >>(std::istream &istr, Tset &s){
    //
    int temp; char ch;
    
    do{istr>>ch;} while (ch != '{');
    
    do{
        istr >> temp; s.InsElem(temp);
        do{istr >> ch ;} while ( (ch != ',') && (ch != '}'));
    }while(ch != '}');
    return istr;
}

std::ostream &operator <<(std::ostream &ostr, const Tset &s){
    //
    int i,n; char ch=' ';
    ostr <<"{";
    n=s.GetMaxPower();
    
    for (i =0; i<n; i++) {
        if (s.isMember(i)) {
            ostr <<ch<<' '<< i;
            ch=',';
        }
    }
    ostr<<"}";
    return ostr;

}

