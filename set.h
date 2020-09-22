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
    int maxPower ;  // максимальная мощность множества
    TBitField Bitfield; // битовое поле для хранения хар-го вектора
public:
    Tset(int mp);
    Tset(const Tset &s);
    Tset(const TBitField &bf);
    operator TBitField();
    // доступ к битам
    int GetMaxPower (void) const; // максимальная мощность множества
    void InsElem(const int n);    // включить элемент в множество
    void DelElem(const int n);    // удалить элемент из множества
    int isMember(const int n) const;  // проверить наличие элемента в
    // множестве
    
    // теоретико-множественные операции
    int operator == (const Tset &s); // сравнение
    Tset &operator = (const Tset &s); // присваивание
    Tset operator + (const int n);    // включение элемента в множество
    Tset operator - (const int n);    // удаление элемента из множества
    Tset operator + (const Tset &s);  // объединение
    Tset operator * (const Tset &s);  // пересечение
    Tset operator ~ (void);
    friend std::istream &operator>>(std::istream &istr, Tset &bf);
    friend std::ostream &operator<<(std::ostream &ostr, const Tset &bf);
    
};

#endif /* set_hpp */
