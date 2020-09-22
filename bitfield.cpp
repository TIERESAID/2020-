//
//  bitfield.cpp
//  Data Structures
//
//  Created by Huncho on 19/09/2020.
//  Copyright © 2020 TIERE. All rights reserved.
//

#include "bitfield.h"

TBitField::TBitField(int len):Bitlen(len){
    MemLen = (len+15) >> 4;
    pMen = new TELEM[MemLen];
    
    if (pMen != nullptr) {
        for (int i =0; i<MemLen; i++) {
            pMen[i]=0;
        }
    }
}


    TBitField::TBitField(const TBitField &bf){
        Bitlen =bf.Bitlen;
        MemLen = bf.Bitlen;
        pMen = new TELEM[MemLen];
        if (pMen != nullptr) {
            for (int i=0; i<MemLen; i++) {
                bf.pMen[i];
            }
        }
    }


        TBitField::~TBitField(){
            delete pMen;
            pMen = nullptr;
        }



 int TBitField::GetMemindex(const int  n) const {
    return n >> 4;
}
    


    TELEM TBitField::GetMemMask(const int n) const {
            return 1 << (n&15);
        }
        


        int TBitField::Getlength(void) const {
            return Bitlen;
        }




        void TBitField::SetBit(const int n){
            if ((n>-1) && (n<Bitlen)) {
                pMen[GetMemindex(n)] |= GetMemMask(n);
            }
        }
        //



void TBitField::ClrBit(const int n){
    if ((n>-1) && (n<Bitlen)) {
        pMen[GetMemindex(n)] &=~GetMemMask(n);
    }
}

//
int TBitField :: GetBit(const int n) const {
    if ((n>-1) && (n<Bitlen)) {
        return pMen[GetMemindex(n)] & GetMemMask(n);
    }
    return 0;
}


        TBitField & TBitField :: operator =(const TBitField &bf){
            Bitlen = bf.Bitlen;
            
            if (MemLen != bf.MemLen) {
                MemLen = bf.MemLen;
            if (pMen !=nullptr) {
                delete pMen;
            }
            pMen = new TELEM[MemLen];
            }
            
        if (pMen != nullptr) {
            for (int i =0 ; i<MemLen; i++) {
                pMen[i] = bf.pMen[i];
           }
        }
              return *this;
        }
            
        
        int TBitField::operator==(const TBitField &bf){
            int res =1 ;
            if (Bitlen !=bf.Bitlen) {
                res = 0 ;
            }
            else
                for (int i=0 ; i<MemLen; i++)
                    if (pMen[i] != bf.pMen[i])
                    {res = 0 ; break ;}
            return res;
        }
    ///
        
    TBitField TBitField::operator |(const TBitField &bf){
        int i , len = Bitlen;
        if (bf.Bitlen >len) {
            len = bf.Bitlen;
        }
        TBitField temp(len);
        for (i =0 ; i<MemLen; i++) {
            temp.pMen[i] = pMen[i];
        }
        for (i =0 ; i<bf.MemLen; i++) {
            temp.pMen[i] |= bf.pMen[i];
        }
        return temp;
    }

TBitField TBitField::operator&(const TBitField &bf){
    int i, len =Bitlen;
    if (bf.Bitlen >len) {
        len = bf.Bitlen;
    }
    TBitField temp(len);
    for ( i =0 ; i<MemLen; i++) {
        temp.pMen[i] = pMen[i];
    }
    for ( i =0 ; i<bf.MemLen; i++) {
        temp.pMen[i] &= bf.pMen[i];
    }
    return temp;
}

TBitField TBitField::operator~(void){
    int len =Bitlen;
    TBitField temp(len);
    for ( int i =0 ; i<MemLen; i++) {
        temp.pMen[i] = ~pMen[i];
    }
    return temp;
}

//
//
std::istream &operator >>(std::istream &istr , TBitField &bf){
    //
    //
    //
    int i =0; char ch;
    //
    do {
        istr >> ch;
    } while (ch != ' ');
    
    while (1) {
        istr >> ch;
        if (ch == '0') {
            bf.ClrBit(i++);
        }
        else if(ch == '1') bf.SetBit(i++);
        else break;
        }
        return istr;
    }


std::ostream &operator <<(std::ostream &ostr , const TBitField &bf){
    //
    //
    int len = bf.Getlength();
    for (int i = 0; i<len; i++) {
        if ( bf.GetBit(i) ) {
            ostr <<'1';
        }
            else ostr<<'1';
    }
    return ostr;
}



