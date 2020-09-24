#ifndef _BITFIELD_H
#define _BITFIELD_H

#include <iostream>
#include <stdlib.h>

typedef unsigned int TELEM ;

class TBitField{
    private :
    int Bitlen ;  // длина битового поля - макс. к-во битов
    TELEM *pMen;  // память для представления битового поля
    int MemLen;   // к-во эл-тов Мем для представления бит.поля
    int GetMemindex(const int n) const ; // индекс в pМем для бита n
    TELEM GetMemMask(const int ) const ;  // битовая маска для бита n
    
public:
    TBitField(int len); // Parameterized Constructors
    
    TBitField(const TBitField &bf);
    ~TBitField();
    
    // доступ к битам
    
    int Getlength(void) const; // получить длину (к-во битов)
    void SetBit(const int n);  // установить бит
    void ClrBit(const int n);  // очистить бит
    int GetBit(const int n) const; // получить значение бита
    
    // битовые операции
    
    int operator ==(const TBitField &bf); // сравнение
    TBitField & operator = (const TBitField &bf); // присваивание
    TBitField  operator | (const TBitField &bf); // операция "или"
    TBitField  operator &(const TBitField &bf); // операция "и"
    TBitField  operator ~(void);               // отрицание
    

    friend std::istream &operator >>(std::istream &istr, TBitField &bf);
    friend std::ostream &operator <<(std::ostream &ostr, const TBitField &bf);
};
#endif
    


