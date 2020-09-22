
#pragma hdrstop
#include <iomanip>
#include "bitfield.h"
#include "set.h"


#pragma argsused
int main(int argc, char* argv[]){
    int n, m,k,count;
    std::cout<<"***Test of the program on the  sets ***"<<std::endl;
    std::cout<<"      Sieve of Eratosthene"<<std::endl;
    std::cout<<"Enter the upper bound of the value - : ";
    std::cin>>n;
    Tset s(n+1);
    
    // заполнение множества
    // проверка до sqrt(n) и удаление кратных
    for (m=2; m<=n; m++)
        s.InsElem(m);
        for (m=2; m*m<=n; m++)
            // если м в s, удаление кратных
        if(s.isMember(m))
            for(k=2*m;k<=n;k+=m)
                if(s.isMember(k)) s.DelElem(k);
    //// elements remaining in s are primes
    std::cout<<std::endl<<" Printing a lot of non-multiple numbers"<<std::endl << s << std::endl;
    
        std::cout<<std::endl<<"Print simple number"<<std::endl;
        count =0; k=1;
        for (m=2; m<=n; m++)
            if(s.isMember(m)){
            count++;
            std::cout<<std::setw(3)<< m <<" ";
        if(k++ %10 == 0 ) std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<" At the first "<< n <<" numbers "<<count<<" prime(s) number(s)"<<std::endl;
    return 0;;
    
}

