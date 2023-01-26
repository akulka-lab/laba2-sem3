#include <iostream>
#include "Data.hpp"
#include "Nudl.hpp"
#include "LinkedList.hpp"
#include "Hash.hpp"
#include "Map.hpp"
#include "CreateFile.hpp"
#include "Menu.hpp"

using namespace::std;




int main(int argc, const char * argv[])
{

    cout << " _______________________________________________________________________  \n" <<
        "|                                                                       | \n" <<
        "|                ~WELCOME TO MENU 2 OF LAB WORK!~                       | \n" <<
        "|                                                                       | \n" <<
        "|____  _________________________________________________________________| \n" <<
        "     |/                                                                   \n" << endl << "Components of the file: \n" << endl;

    Create_Files();
    cout << endl;

    Main_menu();

    return 0;
}

