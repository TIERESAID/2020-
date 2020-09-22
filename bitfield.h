#ifndef _BITFIELD_H
#define _BITFIELD_H

#include <iostream>
#include <stdlib.h>

typedef unsigned int TELEM ;

class TBitField{
    private :
    int Bitlen ;
    TELEM *pMen;
    int MemLen;
    int GetMemindex(const int n) const ;
    TELEM GetMemMask(const int ) const ;
    
public:
    TBitField(int len);
    TBitField(const TBitField &bf);
    ~TBitField();
    
    //
    int Getlength(void) const;
    void SetBit(const int n);
    void ClrBit(const int n);
    int GetBit(const int n) const;
    //
    int operator ==(const TBitField &bf);
    TBitField & operator = (const TBitField &bf);
    TBitField  operator | (const TBitField &bf);
    TBitField  operator &(const TBitField &bf);
    TBitField  operator ~(void);
    

    friend std::istream &operator >>(std::istream &istr, TBitField &bf);
    friend std::ostream &operator <<(std::istream &istream, TBitField &bf);
};
//
//
//
//

#endif
    
    


