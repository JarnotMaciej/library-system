/**
 * @file library-system.cpp
 * @author Maciej Jarnot (mj300741@student.polsl.pl)
 * @brief Library system
 * @version
 * @date 
 *
 */

#include "functions.h"

int main()
{
    date d1(5, 3, 2024);
    d1.display();
    gap();
    for(int i=0; i<10; i++)
    {
        --d1;
        d1.display();
    }

    // date d2=currentDate();
    // d2.display();
    // gap();
    // for(int i=0; i<10; i++)
    // {
    //     --d2;
    //     d2.display();
    // }

    //---------------------------------------------

    // library mainLibrary;
    // admin a;

    // // program should check when book was borrowed
    // openLibrary(mainLibrary);

    // welcome();
    // menu(mainLibrary, a);

    // saveLibrary(mainLibrary);
    // std::cout << "\n\n   Quitting..." << std::endl;
}