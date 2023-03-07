/**
 * @file library-system.cpp
 * @author Maciej Jarnot (mj300741@student.polsl.pl)
 * @brief Library system
 * @version v2
 * @date 07.03.2023
 *
 */

#include "functions.h"

int main()
{
    // date d1(5, 3, 2024);
    // d1.display();
    // gap();
    // for(int i=0; i<10; i++)
    // {
    //     --d1;
    //     d1.display();
    // }
    // gap();
    // std::cout << "+12: " << d1 + 12 << std::endl;


    // date d2=currentDate();
    // d2.display();
    // gap();
    // for(int i=0; i<10; i++)
    // {
    //     --d2;
    //     d2.display();
    // }

    //---------------------------------------------

    library mainLibrary;
    admin a;

    // program should check when book was borrowed
    openLibrary(mainLibrary);

    welcome();
    menu(mainLibrary, a);

    saveLibrary(mainLibrary);
    std::cout << "\n\n   Quitting..." << std::endl;
}