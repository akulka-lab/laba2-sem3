
#ifndef Data_hpp
#define Data_hpp

#include <stdio.h>
template <typename D, typename T>
struct Data
{
    D key;
    T DATA;
    
    Data& operator = (Data<T,D> b)
    {
        this->DATA = b.DATA;
        this->key = b.key;
        return *this;
    }
    
    bool operator == (Data<D,T> b)
    {
        if (this->key == b.key && this->DATA == b.DATA)
            return 1;
        else
            return 0;
    }
};

#endif /* Data_hpp */
