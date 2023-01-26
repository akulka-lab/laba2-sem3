#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Hash.hpp"

template <class D, class T>
class Map
{
private:
    Hash<D, T>* basa = new Hash<D ,T>;
    int lenkash = 5;
public:

    Data<D,T> kash[5];
    Map(int V);
    void insert(Data<D, T>& a);
    void delit(D item);
    Nudl<D,T> * Find(D item);
    void print();
};


template<class D, class T>
Map<D, T>::Map(int V)
{
    *basa = Hash<D, T>(V);
}

template <class D, class T>
void Map<D, T>::insert(Data<D, T>& a)
{
    basa->InsertH(a);
}

template <class D, class T>
void Map<D, T>::delit(D item)
{
    basa->DelitH(item);
    for (int i = 0; i < lenkash; i++)
    {
        if (kash[i].key == item)
            for (int j=i; j<lenkash-1; j++)
                kash[j] = kash[j+1];
    }
    
}

template< class D, class T>
Nudl<D, T> * Map<D, T>::Find(D item)
{
    const int m = lenkash;

    for (int i = 0; i < lenkash; i++)
    {
        if (kash[i].key == item)
        {
            if (i > 0)
            {
                Data<D, T> k = kash[i - 1];
                kash[i - 1] = kash[i];
                kash[i] = k;
                Nudl<D,T> * result = new Nudl<D,T>;
                result->data = kash[i-1];
                return result;
            }
            else
            {
                Nudl<D,T> * result= new Nudl<D,T>;
                result->data = kash[i];
                return result;
            }
        }
    }

    Nudl<D,T> * result = basa->FindH(item);
    
    if (result == NULL)
        return NULL;
    
    Data<D,T> a = result->data;

    Data<D, T> byfer[6];
    byfer[0] = a;

    for (int i = 0; i < lenkash; i++)
        byfer[i + 1] = kash[i];
    for (int i = 0; i < lenkash; i++)
        kash[i] = byfer[i];
    
    return result;
}

template < class D, class T>
void Map<D, T> ::print()
{
    basa->PrintH();
}
#endif /* Map_hpp */
//rectangle pro ///// one switch /////
