
#ifndef Nudl_hpp
#define Nudl_hpp

#include <stdio.h>
template <typename D, typename T>
class Nudl
{
public:
    Data<D,T> data;
    Nudl* next;
};

#endif /* Nudl_hpp */
