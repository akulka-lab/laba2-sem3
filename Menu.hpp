#ifndef Menu_hpp
#define Menu_hpp


#include "Map.hpp"
#include "Data.hpp"
#include <chrono>
#include <ctime>
#include <fstream>

#include <stdio.h>

using namespace::std;

void Main_menu();
template <typename D, typename T>
void menu();
template <typename T>
void menu();
void menu();


int menu_var(int count);
int random_int(int max, int min);
int menu_01 ();
int menu_02 ();
/*int input_count ();

void Menu();*/


int menu_var(int count)
{
    int v;
    cin>>v;
    while ( v < 0 || v > count) {
        cout<<("ошибка, попробйте еще раз==>"); // выводим сообщение об ошибке
        cin>>v; // считываем строку повторно
    }
    return v;
}

int random_int(int max=1, int min=0)
{
    return (min + rand()%((max+1)-min));
}

int menu_01 ()
{

    cout << " _______________________________________________________________________  \n" <<
        "|                                                                       | \n" <<
        "|       CHECKING HASHING ALGORITHMS AND COLLISION ELIMINATION           | \n" <<
        "|                                                                       | \n" <<
        "|                        CHOOSE A FORMAT DATA<D,T>                      | \n" <<
        "|                                                                       | \n" <<
        "|____  _________________________________________________________________| \n" <<
        "     |/                                                                   \n" << endl <<
        " _______________________________________________________________________  \n" <<
        "|                                                                       | \n" <<
        "|                      Choose a further action:                         | \n" <<
        "|                                                                       | \n" <<
        "|   1 - DATA < int, int >                                               | \n" <<
        "|   2 - DATA < string, int >                                            | \n" <<
        "|   3 - DATA < string, string >                                         | \n" <<
        "|   4 - Tests - Sequence                                                | \n" <<
        "|                                                                       | \n" <<
        "|   0 - finish work                                                     | \n" <<
        "|____  _________________________________________________________________| \n" <<
        "     |/                                                                   \n" << endl;

  
    cout << "Enter the selected number: ";

    int r = menu_var(4);
    return r;
}

int menu_02 ()
{
    cout << " _______________________________________________________________________  \n" <<
        "|                                                                       | \n" <<
        "|          The menu for selecting works with the hashing map!           | \n" <<
        "|                                                                       | \n" <<
        "|____  _________________________________________________________________| \n" <<
        "     |/                                                                   \n" << endl <<
        " _______________________________________________________________________  \n" <<
        "|                                                                       | \n" <<
        "|                      Choose a further action:                         | \n" <<
        "|                                                                       | \n" <<
        "|   1 - display the map on the screen                                   | \n" <<
        "|   2 - element search                                                  | \n" <<
        "|   3 - deleting an element                                             | \n" <<
        "|   4 - insert a new element                                            | \n" <<
        "|                                                                       | \n" <<
        "|   0 - RETURN TO THE MAIN MENU                                         | \n" <<
        "|____  _________________________________________________________________| \n" <<
        "     |/                                                                   \n" << endl;

    cout << "Enter the selected number: ";

    int r = menu_var(4);
    return r;
}


void Main_menu()
{
    while (1 == 1)
    {
        int var = menu_01();
        switch (var)
        {
            case 0:
                return;
                
            case 1:
                menu<int, int>();
                break;
            
            case 2:
                menu<int>();
                break;
                
            case 3:
                menu();
                break;
                
            default:
                break;
        }
    }
    

}


template <typename D, typename T>
void menu()
{
    cout<<"Enter the number of items:  ";
    int n_count = menu_var(10000000);
    Data<D,T> * dt = new Data<D,T>[n_count];
    for (int i=0; i<n_count; i++)
    {
        dt[i].key = random_int(2000,0);
        dt[i].DATA = random_int(100000,-100000);
    }
    auto begin1 = chrono::steady_clock::now();
    Map<D,T> map(n_count/8);
    for (int i=0; i<n_count; i++)
        map.insert(dt[i]);
    auto end1 = chrono::steady_clock::now();
    auto elapsed_ms_selectionSort1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
    cout << "The execution time of creating a hashing map = " <<  elapsed_ms_selectionSort1.count() <<" ms" <<endl;
    
    
    while (1==1)
    {
        int var = menu_02();
        switch (var)
        {
            case 0:
                return ;
                
            case 1:
            {
                cout<<"~ Table ~"<<endl;
                map.print();
                break;
            }
            case 2:
            {
                int key;
                cout<<"Enter the key = ";
                cin>> key;
                Nudl<D,T> * res = map.Find(key);
                if (res == NULL)
                {
                    cout<<"the item is not in the list"<<endl;
                    break;
                }
          //      Data<D,T> result = map.Find(key);
                cout<< res->data.key<< " ==> "<<res->data.DATA<<endl;
                break;
            }
                
            case 3:
            {
                int key;
                cout<< "Enter the key = ";
                cin>> key;
                map.delit(key);
                
                break;
            }
            case 4:
            {
                Data<D,T> input;
                cout<< "Enter the key = ";
                cin>> input.key;
                cout<< "Enter the DATA = "; 
                cin>> input.DATA;
                map.insert(input);
                break;
            }
                
            default:
                break;
        }
    }
    return;
}


template <typename T>
void menu()
{
    cout << "Enter the number of items:  ";
    int n_count = menu_var(10000000);
    string st[]= { "Johnson", "Williams", "Carter", "Jones", "Thomas", "Campbell", "Phillips", "Parker", "Wilson", "Davis", "Martin", "Edwards", "Ivanov", "Vasiliev", "Petrov", "Smirnov", "Mikhailov", "Fedorov", "Sokolov", "Yakovlev", "Popov", "Andreev", "Alexeev", "Alexandrov", "Lebedev", "Grigoriev", "Stepanov", "Semenov", "Pavlov", "Bogdanov",  "Nikolaev", "Dmitriev", "Egorov", "Wolves", "Kuznetsov", "Nikitin", "Solovyov", "Timofeev", "Eagles", "Afanasyev", "Filippov", "Sergeyev","Zakharov", "Matveev", "Scott", "Bogdanov", "Nikolaev", "Dmitriev", "Egorov", "Wolves", "Kuznetsov", "Nikitin", "Solovyov", "Timofeev", "Eagles", "Afanasyev", "Filippov", "Sergeyev","Zakharov", "Matveev", "Young","Ivanov", "Vasiliev", "Petrov", "Smirnov", "Mikhailov", "Fedorov", "Sokolov", "Yakovlev", "Popov", "Andreev", "Alexeev", "Alexandrov", "Lebedev", "Grigoriev", "Stepanov", "Semenov", "Pavlov", "Bogdanov", "Nikolaev", "Dmitriev", "Egorov", "Wolves", "Kuznetsov", "Nikitin", "Solovyov", "Timofeev", "Eagles", "Afanasyev", "Filippov", "Sergeyev","Zakharov","Ward", "Watson", "Murphy", "Howard","Bailey", "Bogdanov", "Nikolaev", "Dmitriev", "Egorov", "Wolves", "Kuznetsov", "Nikitin", "Solovyov", "Timofeev", "Eagles", "Afanasyev", "Filippov", "Sergeyev","Zakharov", "Matveev", "Scott", "Walker", "Barnes","Ivanov", "Vasiliev", "Petrov", "Smirnov", "Mikhailov", "Fedorov", "Sokolov", "Yakovlev", "Popov", "Andreev", "Alexeev", "Alexandrov", "Lebedev", "Grigoriev", "Stepanov", "Semenov", "Pavlov", "Bogdanov", "Nikolaev", "Dmitriev", "Egorov", "Wolves", "Kuznetsov","end" };

    
    Data<string,T> * dt = new Data<string,T>[n_count];
    for (int i=0; i<n_count; i++)
    {
        dt[i].key = st[random_int(135,0)];
        dt[i].DATA = random_int(100000,-100000);
    }
    auto begin1 = chrono::steady_clock::now();
    Map<string,T> map(n_count/8);
    for (int i=0; i<n_count; i++)
        map.insert(dt[i]);
    auto end1 = chrono::steady_clock::now();
    auto elapsed_ms_selectionSort1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
    cout << "The execution time of creating a hashing map = "  <<  elapsed_ms_selectionSort1.count() <<" ms" <<endl;
    
    
    while (1==1)
    {
        int var = menu_02();
        switch (var)
        {
            case 0:
                return ;
                break;
                
            case 1:
            {
                cout << "~ Table ~" << endl;
                map.print();
                break;
            }
            case 2:
            {
                string key;
                cout<< "Enter the key = ";
                cin>> key;
                Nudl<string,T> * res = map.Find(key);
                if (res == NULL)
                {
                    cout << "the item is not in the list" << endl;
                    break;
                }
                cout<< res->data.key<< " ==> "<<res->data.DATA<<endl;
                
                //Data<string,T> result = map.Find(key);
                //cout<< result.key<< " ==> "<<result.DATA<<endl;
                break;
            }
                
            case 3:
            {
                string key;
                cout << "Enter the key = ";
                cin>> key;
                map.delit(key);
                
                break;
            }
            case 4:
            {
                Data<string,T> input;
                cout << "Enter the key = ";
                cin>> input.key;
                cout << "Enter the DATA = ";
                cin >> input.DATA;
                map.insert(input);
                break;
            }
                
            default:
                break;
        }
    }
    return;
}


void menu()
{
    cout << "Enter the number of items:  ";
    int n_count = menu_var(10000000);
    ifstream file_in_01("Names.txt");
    ifstream file_in_02("tel.txt");
    string array_01[200], array_02[200];
    
    if (!file_in_01.is_open() && !file_in_02.is_open())
        cout<<"error"<<endl;
    else
    {
        for(int i=0; i<100; i++)
        {
            getline(file_in_01,array_01[i]);
            getline(file_in_02,array_02[i]);
        }
    }
    Data<string,string> * dt = new Data<string,string>[n_count];
    
    for (int i=0; i<n_count; i++)
    {
        dt[i].key = array_01[random_int(100,0)];
        dt[i].DATA = array_02[random_int(100,0)];
    }
    auto begin1 = chrono::steady_clock::now();
    Map<string,string> map(n_count/8);
    for (int i=0; i<n_count; i++)
        map.insert(dt[i]);
    auto end1 = chrono::steady_clock::now();
    auto elapsed_ms_selectionSort1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
    cout << "The execution time of creating a hashing map = " <<  elapsed_ms_selectionSort1.count() <<" ms" <<endl;
    
    
    while (1==1)
    {
        int var = menu_02();
        switch (var)
        {
            case 0:
                return ;
                break;
                
            case 1:
            {
                cout << "~ Table ~" << endl;
                map.print();
                break;
            }
            case 2:
            {
                string key;
                cout << "Enter the key = ";
                cin>> key;
                Nudl<string,string> * res = map.Find(key);
                if (res == NULL)
                {
                    cout << "the item is not in the list" << endl;
                    break;
                }
                cout<< res->data.key<< " ==> "<<res->data.DATA<<endl;
                
                //Data<string,string> result = map.Find(key);
                //cout<< result.key<< " ==> "<<result.DATA<<endl;
                break;
            }
                
            case 3:
            {
                string key;
                cout << "Enter the key = ";
                cin>> key;
                map.delit(key);
                
                break;
            }
            case 4:
            {
                Data<string,string> input;
                cout << "Enter the key = ";
                cin>> input.key;
                cout << "Enter the DATA  = ";
                cin>> input.DATA;
                map.insert(input);
                break;
            }
                
            default:
                break;
        }
    }
    return;
}




#endif /* Menu_hpp */
