#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
#include "Data.hpp"
#include "Nudl.hpp"
#include <assert.h>


using namespace::std;

template <typename D, typename T>
class LinkedList
{
private:
    Nudl<D,T> * ne1 ;//= new Nudl<D,T>;
    void CheckCountRange(int undex);
public:
    LinkedList();
    ~LinkedList();
    int GetLength();
    Data<D,T> GetFirst();
    Data<D,T> GetLast();
    Data<D,T> GetIndex(int index);
    void Append(Data<D,T> item);
    void Prepend(Data<D,T> item);
    void InsertAt(Data<D,T> item, int index);
    void SetAt(Data<D,T> item, int index);
    void Remove(int index);
    void Delit(D item);
    Nudl<D,T> * Find(D item);
    void PrintLinkedList();
};

template <typename D, typename T>
void LinkedList<D,T> :: CheckCountRange(int index)
{
    if ((index >= this->GetLength()) || (index < 0))
        throw invalid_argument ("Index out of range LinkedList<D,T>");
}



template <typename D, typename T>
LinkedList<D,T> :: LinkedList()
{
    //ne1 = new Nudl<D,T>;
    ne1 = NULL;
}

template <typename D, typename T>
LinkedList<D,T> ::~LinkedList()
{
    Nudl<D,T> * temp = this->ne1;
    Nudl<D,T> * dt;
    
    while (temp != NULL)
    {
        dt = temp;
        temp = temp->next;
        delete dt;
    }
}

template <typename D, typename T>
int LinkedList<D,T> :: GetLength()
{
    if (ne1 == NULL)
        return 0;
    Nudl<D,T> * temp = this->ne1;
    int length = 1;
    while (temp->next != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

template <typename D, typename T>
Data<D,T> LinkedList<D,T> :: GetFirst()
{
    Data<D,T> temp;
    if (ne1 == NULL)
        return temp;
    else
        return this->ne1->data;
}

template <typename D, typename T>
Data<D,T> LinkedList<D,T> :: GetLast()
{
    Data<D,T> tempdata;
    Nudl<D,T> * temp = this->ne1;
    if (temp == NULL)
        return tempdata;
    else
    {
        int count = 0;
        while (temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }
    }
        return temp->data;
}

template <typename D, typename T>
Data<D,T> LinkedList<D,T> :: GetIndex(int index)
{
    Data<D, T> tempdata;
    Nudl<D, T>* temp = this->ne1;
    /*try
    {
        CheckCountRange(index);
    }
    catch (invalid_argument& error)
    {
        cout << "Error (InsertAt(Data<D, T> item, int index)): " << error.what() << endl;
        return tempdata;
    }
    Nudl<D,T> * temp = this->ne1;
    if (temp != NULL)
        return tempdata;
    else*/
        for (int i=0; i < index; i++)
            temp = temp->next;
        return temp->data;
}

template <typename D, typename T>
void LinkedList<D,T> :: Append(Data<D,T> item)
{
    
    Nudl<D,T> * newNudl = new Nudl<D,T>;
    newNudl->data = item;
    newNudl->next = NULL;
    Nudl<D,T> * temp = this->ne1;
    if (temp == NULL)
        this->ne1 = newNudl;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNudl;
    }
}

template <typename D, typename T>
void LinkedList<D,T> :: Prepend(Data<D,T> item)
{
    Nudl<D,T> * newNudl = new Nudl<D,T>;
    newNudl->data = item;
    newNudl->next = NULL;
    Nudl<D,T> * temp = this->ne1;
    if (temp == NULL)
        this->ne1 = newNudl;
    else
    {
        newNudl->next = this->ne1;
        this->ne1 = newNudl;
    }
}

template <typename D, typename T>
void LinkedList<D,T> :: InsertAt(Data<D, T> item, int index)
{
    try
    {
        CheckCountRange(index);
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (InsertAt(Data<D, T> item, int index)): "<<error.what()<<endl;
        return;
    }
    Nudl<D,T> * newNudl = new Nudl<D,T>;
    newNudl->data = item;
    newNudl->next = NULL;
    Nudl<D,T> * temp = this->ne1;
    Nudl<D,T> * tempp;
    for (int i=0; i<index-1; i++)
    {
        temp = temp->next;
        tempp = temp->next;
    }
    temp->next = newNudl;
    newNudl->next = tempp;
}

template <typename D, typename T>
void LinkedList<D,T> :: SetAt(Data<D, T> item, int index)
{
    try
    {
        CheckCountRange(index);
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (SetAt(Data<D, T> item, int index)): "<<error.what()<<endl;
        return;
    }
    Nudl<D,T> * temp = this->ne1;
    for (int i=0; i<index; i++)
        temp = temp->next;
    temp->data = item;
}

template <typename D, typename T>
void LinkedList<D,T> :: Remove (int index)
{
    try
    {
        CheckCountRange(index);
    }
    catch (invalid_argument& error)
    {
        cout<<"Error (Remove (int index)): "<<error.what()<<endl;
        return;
    }
    Nudl<D,T> * temp = this->ne1;
    Nudl<D,T> * tempp = temp->next;
    if (index==0)
    {
        this->ne1 = tempp;
        delete temp;
    }
    else
    {
        for (int i=0; i<index-1; i++)
        {
            temp = temp->next;
            tempp = temp->next;
        }
        temp->next = tempp->next;
        delete tempp;
    }
}
/*
template<class D, class T>
void LinkedList<D, T> ::Delit(D item)
{

    if (ne1->data.key == item)
    {
        Nudl<D, T>* ne = this->ne1;
        ne1 = ne1->next;
        delete(ne);
    }

    else
        //if (ne1->data.key != item)
    {
        Nudl<D, T>* ne = this->ne1;

        while (ne->data.key != item)
        {
            ne = ne->next;
            if (ne == NULL)
            {
                cout << endl << "### нет такого элемента в списке ###" << endl;
                return;
            }
        
        }
       
        Nudl<D, T>* ne2 = ne->next;

        ne->next = ne2->next;
        delete(ne2);
        
    }
}
*/

 template <typename D, typename T>
void LinkedList<D,T> :: Delit(D item)
{
    Nudl<D,T> * temp = this->ne1;
    if (temp == NULL)
        return;
    Nudl<D,T> * tempp = temp->next;
    if (temp->data.key == item)
    {
        this->ne1 = tempp;
        delete temp;
        return;
    }
    while (tempp->data.key != item)
    {
        if (tempp->next == NULL)
        {
            cout<<endl<<"there is no such item in the list!"<<endl<<endl;
            return;
        }
        temp = temp->next;
        tempp = temp->next;
    }
    temp->next = tempp->next;
    delete tempp;
}



template <typename D, typename T>
Nudl<D,T> * LinkedList<D, T> ::Find(D item)

{
    Nudl<D, T>* temp = this->ne1;
    while (temp != NULL)
    {
        if (temp->data.key == item)
            return temp;
        temp =temp->next;
    }
    cout<< "there is no such item in the list!" <<endl;
    return NULL;
}


/*
template < class D, class T>
T LinkedList<D, T> ::Find(D item)
{
    Nudl<D, T>* ne = this->ne1;
    while (ne->data.key != item)
    {
        ne = ne->next;
        if (ne == NULL)
        {
            cout << "### нет такого элемента в списке ###" << endl;
            return 0;
            break;
        }
    }
    
    if(ne != NULL)
        return ne->data.DATA;
    return 0;
}
 */
 
template <typename D, typename T>
void LinkedList<D,T> :: PrintLinkedList()
{
    Nudl<D,T> * temp = this->ne1;
    if (temp == NULL)
    {
        cout<<"the list is empty"<<endl;
        return;
    }
    int i = 0;
    while (temp != NULL)
    {
        cout<<i<<"  key= "<<temp->data.key<<" : data= "<<temp->data.DATA<<"  ||  ";
        temp = temp->next;
        i++;
    }
    cout<<endl;
    return;
}
#endif /* LinkedList_hpp */
