
#pragma hdrstop
#include <iomanip>
#include "bitfield.h"
#include "set.h"


#pragma argsused
int main(int argc, char* argv[]){
    int n, m,k,count;
    std::cout<<"Test of the program :: set concept"<<std::endl;
    std::cout<<"      Sieve of Eratosthene"<<std::endl;
    std::cout<<"Enter the upper bound of tbe integer value: ";
    std::cin>>n;
    Tset s(n+1);
    //
    
    for (m=2; m<=n; m++)
        for (m=2; m*m<=n; m++)
        if(s.isMember(m))
            for(k=2*m;k<=n;k+=m)
                if(s.isMember(k)) s.DelElem(k);
    
    
        std::cout<<"Print simple numner"<<std::endl;
        count =0; k=1;
        
        for (m=2; m<=n; m++)
            if(s.isMember(m)){
            count++;
            std::cout<<std::setw(3)<< m <<" ";
        if(k++ %10 == 0 ) std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<" At the first "<< n <<"cases "<<count<<"simple"<<std::endl;
    return 0;;
    
}

