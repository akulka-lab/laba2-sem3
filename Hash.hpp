
#ifndef Hash_hpp
#define Hash_hpp

#include <stdio.h>
#include <string>
#include <type_traits>
#include "LinkedList.hpp"
#include "Data.hpp"

using namespace::std;



template<typename D>
int FunctionHash(D key, int size)
{
    return (key % size);
}

template<>
int FunctionHash(string key, int size)
{
    int n = 0;
    for (int i=0; i<key.length(); i++)
        n = n +key[i];
    return (n % size);
}

template<typename D, typename T>
class Hash
{
private:
    LinkedList<D,T> * list;
    int capacity;
public:
    Hash();
    Hash(int s);
    void InsertH(Data<D,T> & item);
    void DelitH(D item);
    void PrintH();
    Nudl<D, T> * FindH(D item);
   
    
    int chekprime(int n)
    {
        int i = 0;
        if (n == 1 || n == 0)
        {
            return 0;
        }

        for (i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }

    int getprime(int n)
    {
        if (n % 2 == 0)
        {
            n++;
        }

        while (!chekprime(n))
        {
            n = n + 2;
        }
        return n;
    }


};


template <class D, class T>
Hash<D, T>::Hash()
{

}

template <class D, class T>
Hash<D, T>::Hash(int V)
{
    capacity  = getprime(V);

    list = new LinkedList<D, T>[capacity]();
}

template <class D, class T>
void Hash<D, T>::InsertH(Data<D,T>& a)
{
    int y = 0;
    for (int j = 0; j < this->capacity; j++)
    {
        y = y + this->list[j].GetLength();
    }

    if (y / capacity > 3)
    {
        int size = this->capacity * 3;
        LinkedList<D,T> * x =  new LinkedList<D, T>[size]();
        
        for (int j = 0; j < this->capacity; j++)
        {
            
            int sizelist = this->list[j].GetLength();
            for (int k = 0; k < sizelist; k++)
            {
                int index1;
                index1 = FunctionHash(this->list[j].GetIndex(k).key,size);
                x[index1].Prepend(this->list[j].GetIndex(k));
            }
        }
        this->capacity = size;
        this->list = x;
        
    }

    int index;
        index = FunctionHash(a.key,capacity);
    list[index].Prepend(a);
}

template <class D, class T>
void Hash<D, T>::DelitH(D item)
{
    int index = FunctionHash(item,capacity);
    list[index].Delit(item);
}

template<class D, class T>
Nudl<D,T> * Hash<D,T>::FindH(D item)
{
    int index = FunctionHash(item, capacity);
    Nudl<D,T> * result = list[index].Find(item);
    
    return result;
}

template <class D, class T>
void Hash<D, T>::PrintH()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << endl;

        cout << "hash: " << i << "-->";
        list[i].PrintLinkedList();
    }

    cout << capacity<<endl;
}




#endif /* Hash_hpp */
