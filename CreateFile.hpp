
#ifndef CreateFile_hpp
#define CreateFile_hpp

#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>


using namespace::std;
int random_int2(int max, int min);
void Create_Files();

int random_int2(int max=1, int min=0)
{
    return (min + rand()%((max+1)-min));
}

void Create_Files()
{
    setlocale(LC_ALL, "ru");
    
    string name_file_Name = "Names.txt";
    string name_file_tel = "tel.txt";
    string st[]={"Johnson", "Williams", "Carter", "Jones", "Thomas", "Campbell", "Phillips", "Parker", "Wilson", "Davis", "Martin", "Edwards", "Ivanov", "Vasiliev", "Petrov", "Smirnov", "Mikhailov", "Fedorov", "Sokolov", "Yakovlev", "Popov", "Andreev", "Alexeev", "Alexandrov", "Lebedev", "Grigoriev", "Stepanov", "Semenov", "Pavlov", "Bogdanov",  "Nikolaev", "Dmitriev", "Egorov", "Wolves", "Kuznetsov", "Nikitin", "Solovyov", "Timofeev", "Eagles", "Afanasyev", "Filippov", "Sergeyev","Zakharov", "Matveev", "Scott", "Bogdanov", "Nikolaev", "Dmitriev", "Egorov", "Wolves", "Kuznetsov", "Nikitin", "Solovyov", "Timofeev", "Eagles", "Afanasyev", "Filippov", "Sergeyev","Zakharov", "Matveev", "Young","Ivanov", "Vasiliev", "Petrov", "Smirnov", "Mikhailov", "Fedorov", "Sokolov", "Yakovlev", "Popov", "Andreev", "Alexeev", "Alexandrov", "Lebedev", "Grigoriev", "Stepanov", "Semenov", "Pavlov", "Bogdanov", "Nikolaev", "Dmitriev", "Egorov", "Wolves", "Kuznetsov", "Nikitin", "Solovyov", "Timofeev", "Eagles", "Afanasyev", "Filippov", "Sergeyev","Zakharov","Ward", "Watson", "Murphy", "Howard","Bailey", "Bogdanov", "Nikolaev", "Dmitriev", "Egorov", "Wolves", "Kuznetsov", "Nikitin", "Solovyov", "Timofeev", "Eagles", "Afanasyev", "Filippov", "Sergeyev","Zakharov", "Matveev", "Scott", "Walker", "Barnes","Ivanov", "Vasiliev", "Petrov", "Smirnov", "Mikhailov", "Fedorov", "Sokolov", "Yakovlev", "Popov", "Andreev", "Alexeev", "Alexandrov", "Lebedev", "Grigoriev", "Stepanov", "Semenov", "Pavlov", "Bogdanov", "Nikolaev", "Dmitriev", "Egorov", "Wolves", "Kuznetsov","end"};
    string ss, tel;
    ofstream fileN;
    fileN.open(name_file_Name);
    int k;
    if (!fileN.is_open())
        cout<<"error"<<endl;
    else
    {
        for (int i = 0; i<20; i++)
        {
            k = random_int2(158,0);
            fileN<<st[k]<<endl;
            // cout<<st[i]<<endl;
        }
    }
    fileN.close();
    
    fileN.open(name_file_tel);
    if (!fileN.is_open())
        cout<<"error"<<endl;
    else
    {
        for (int i = 0; i<20; i++)
        {
            ss = "+7 (495) " + to_string(random_int2(9999999,1000000));
            fileN<<ss<<endl;
            //cout<<st[i]<<endl;
        }
        
    }
    fileN.close();
    
    
    ifstream fileNr;
    fileNr.open(name_file_Name);
    if (!fileNr.is_open())
        cout<<"error"<<endl;
    else
    {
        // fileN<<"tyr"<<endl;
        while (!fileNr.eof())
        {
            getline(fileNr,ss);
            cout<<ss<<endl;
        }
        
    }
    fileNr.close();
    
    fileNr.open(name_file_tel);
    if (!fileNr.is_open())
        cout<<"error"<<endl;
    else
    {
        // fileN<<"tyr"<<endl;
        while (!fileNr.eof())
        {
            getline(fileNr,ss);
            cout<<ss<<endl;
        }
    }
    return;
}

#endif /* CreateFile_hpp */
