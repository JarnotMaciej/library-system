/**
 * @file functions.cpp
 * @author Maciej Jarnot (mj300741@student.polsl.pl)
 * @brief Library system
 * @version 
 * @date 
 *
 */

#include "functions.h"

long int book::ID = 0;
long int user::ID = -1;
long int library::numOfBooks = 0;
long int library::numOfUsers = 0;

book::book()
{
    title = "no-title";
    authorName = "no-author-name";
    authorSurname = "no-author-surname";
    borrowed = false;
    borrowedBy = 0;
    bookID = ++ID;
}

book::book(std::string t, std::string an, std::string asn)
{
    title = t;
    authorName = an;
    authorSurname = asn;
    borrowed = false;
    borrowedBy = 0;
    bookID = ++ID;
}

void welcome()
{
    std::cout << R"(                                                        
  .         .                                   .              
  |      o  |                                  _|_             
  |      .  |.-. .--..-.  .--..  .  .--..  ..--.|  .-. .--.--. 
  |      |  |   )|  (   ) |   |  |  `--.|  |`--.| (.-' |  |  | 
  '---'-' `-'`-' '   `-'`-'   `--|  `--'`--|`--'`-'`--''  '  `-
                                 ;         ;                   
                              `-'       `-'                    )"
              << std::endl
              << std::endl;
}

void menu(library &l, admin &a)
{

    int menuOption = 0;
    do
    {
        std::cout << R"(
  ------------------   Menu   ------------------
  
  1) Library overview (Information about library)
  2) All books
  3) All users
  4) Search book
  5) Search user
  6) About app
  7) Admin panel

  9) Borrow / return the book
  0) Exit application
  
    Enter your choice: )";
        std::cin >> menuOption;
        switch (menuOption)
        {
        case 1:
            system("cls");
            welcome();
            l.libraryInfo();
            break;
        case 2:
            system("cls");
            welcome();
            l.showAllBooks();
            break;
        case 3:
            system("cls");
            welcome();
            l.showAllUsers();
            break;
        case 4:
            system("cls");
            welcome();
            displayBookMenu(l);
            break;
        case 5:
            system("cls");
            welcome();
            displayUserMenu(l);
            break;
        case 6:
            system("cls");
            welcome();
            aboutApp();
            break;
        case 7:
            system("cls");
            welcome();
            // std::cout << "  Nothing interesting here\n";
            {
                std::string login, psw;
                std::cout << R"(
  ---------------   Admin login   --------------)"
                          << std::endl
                          << std::endl;
                std::cout << "  Enter your login: ";
                std::cin >> login;
                std::cout << "  Enter your password: ";
                std::cin >> psw;

                //---------------- testing section
                // login = "admin";
                // psw = "zaq1@WSX";
                //----------------

                if (a.login(login, psw) == true)
                {
                    adminPanel(l, a);
                }
                else
                {
                    std::cout << std::endl
                              << "  [Incorrect login or password]" << std::endl;
                }
            }
            break;
        case 9:
            system("cls");
            welcome();
            borrowReturnMenu(l);
            break;
        default:
            system("cls");
            welcome();
            break;
        }
    } while (menuOption != 0);
}

void displayBookMenu(library &l)
{
    int menuOption = 0;
    do
    {
        std::cout << R"(
  --------------   Display book   --------------
  
  1) Search by ID
  2) Search by book name
  3) Search by author
  4) Show borrowed books
  5) Show not borrowed books

  0) Quit book menu
  
    Enter your choice: )";
        std::cin >> menuOption;
        switch (menuOption)
        {
        case 1:
        {
            long int bIDinput = 0;
            system("cls");
            welcome();
            std::cout << "  ----------    Display book by ID    ----------\n"
                      << std::endl;
            std::cout << "  Please enter book ID of the book, which you want to display: ";
            std::cin >> bIDinput;
            l.showBook(bIDinput);
        }
        break;
        case 2:
        {
            std::string bookNam;
            std::cout << "  ---------    Search by book name    ----------\n"
                      << std::endl;
            std::cout << "  Please enter the book name: ";
            std::cin >> bookNam;
            l.searchBook(2, bookNam);
        }
        break;
        case 3:
        {
            std::string aNam, aSNam;
            std::cout << "  ---------    Search by the author    ---------\n"
                      << std::endl;
            std::cout << "  Please enter name of the author: ";
            std::cin >> aNam;
            std::cout << "  Please enter surname of the author: ";
            std::cin >> aSNam;
            l.searchBook(3, aNam, aSNam);
        }
        break;
        case 4:
        {
            std::cout << "  ---------    Show borrowed books    ----------\n"
                      << std::endl;
            l.searchBook(4);
        }
        break;
        case 5:
        {
            std::cout << "  --------    Show not borrowed books    --------\n"
                      << std::endl;
            l.searchBook(5);
        }
        break;
        default:
            system("cls");
            welcome();
            break;
        }
    } while (menuOption != 0);
}

void displayUserMenu(library &l)
{
    int menuOption = 0;
    do
    {
        std::cout << R"(
  --------------   Display user   --------------
  
  1) Search by ID
  2) Search by name
  3) Search by surname
  4) Search by name and surname

  0) Quit user menu
  
    Enter your choice: )";
        std::cin >> menuOption;
        switch (menuOption)
        {
        case 1:
        {
            long int uIDinput = 0;
            system("cls");
            welcome();
            std::cout << "  ----------    Display user by ID    ----------\n"
                      << std::endl;
            std::cout << "  Please enter user ID: ";
            std::cin >> uIDinput;
            l.showUser(uIDinput);
        }
        break;
        case 2:
        {
            std::string uNam;
            std::cout << "  ---------    Search by user name    ----------\n"
                      << std::endl;
            std::cout << "  Please enter the name: ";
            std::cin >> uNam;
            l.searchUser(2, uNam);
        }
        break;
        case 3:
        {
            std::string uSNam;
            std::cout << "  ---------    Search by the surname    ---------\n"
                      << std::endl;
            std::cout << "  Please enter surname: ";
            std::cin >> uSNam;
            l.searchUser(3, uSNam);
        }
        break;
        case 4:
        {
            std::string uNam, uSNam;
            std::cout << "  ------    Search by name and surname    ------\n"
                      << std::endl;
            std::cout << "  Please enter name: ";
            std::cin >> uNam;
            std::cout << "  Please enter surname: ";
            std::cin >> uSNam;
            l.searchUser(4, uNam, uSNam);
        }
        break;
        default:
            system("cls");
            welcome();
            break;
        }
    } while (menuOption != 0);
}

void adminPanel(library &l, admin &a)
{

    int menuOption = 0;
    do
    {
        system("cls");
        welcome();

        std::cout << R"(
  ---------------   Admin panel   --------------
  
  1) Edit book
  2) Edit user
  3) Edit library

  4) Add book
  5) Add user

  0) Quit admin panel
  
    Enter your choice: )";
        std::cin >> menuOption;
        switch (menuOption)
        {
        case 1:
        {
            long int bIDinput = 0;
            system("cls");
            welcome();
            std::cout << "  ---------------    Edit book    --------------\n"
                      << std::endl;
            std::cout << "  Please enter book ID of the book, which you want to edit: ";
            std::cin >> bIDinput;
            system("cls");
            welcome();
            a.editBook(l, bIDinput);
        }
        break;
        case 2:
        {
            long int uIDinput = 0;
            system("cls");
            welcome();
            std::cout << "  ---------------    Edit user    --------------\n"
                      << std::endl;
            std::cout << "  Please enter user ID of the user, which you want to edit: ";
            std::cin >> uIDinput;
            system("cls");
            welcome();
            a.editUser(l, uIDinput - 1);
        }
        break;
        case 3:
        {
            system("cls");
            welcome();
            a.editLibrary(l);
        }
        break;
        case 4:
        {
            std::string bTitle, bAName, bASurname;
            system("cls");
            welcome();

            std::cout << "  ----------------    Add book    --------------\n"
                      << std::endl;
            std::cout << "\n  Enter book title: ";
            std::cin >> bTitle;
            std::cout << "\n  Enter author name: ";
            std::cin >> bAName;
            std::cout << "\n  Enter author surname: ";
            std::cin >> bASurname;
            l.addBook(bTitle, bAName, bASurname);
        }
        break;
        case 5:
        {
            std::string uName, uSurname;
            system("cls");
            welcome();

            std::cout << "  ----------------    Add user    --------------\n"
                      << std::endl;
            std::cout << "\n  Enter new user name: ";
            std::cin >> uName;
            std::cout << "\n  Enter new user surname: ";
            std::cin >> uSurname;
            l.addUser(uName, uSurname);
        }
        break;
        default:
            break;
        }
    } while (menuOption != 0);
}

void aboutApp()
{
    std::cout << "  ---------------    About app    --------------\n"
              << std::endl;
    std::cout << "  This app is used for handling library system.\n  In the application you can display information about libary, books or users.\n  You can also edit entries.\n  All data is saved to txt files, which can be opened later." << std::endl;
}

void saveLibrary(const library &l)
{
    {

        try
        {
            std::ofstream saveLibraryFile("library.txt");
            if (saveLibraryFile)
            {
                saveLibraryFile << l.libraryName << " " << l.cityName << std::endl;
                std::cout << "   Library " << l.libraryName << " in " << l.cityName << " saved to library.txt" << std::endl;
            }
            else
            {
                throw error("Directory not found, library info not saved.");
            }
        }
        catch (error e)
        {
            std::cerr << "  " << e.errorText << std::endl;
        }

        try
        {
            std::ofstream saveBooksFile("books.txt");
            if (saveBooksFile)
            {
                for (book i : l.libraryBook)
                {
                    saveBooksFile << i.bookID << " " << i.title << " " << i.authorName << " " << i.authorSurname << " " << i.borrowed;
                    if (i.borrowed == true)
                        saveBooksFile << " " << i.borrowedBy << std::endl;
                    else
                        saveBooksFile << std::endl;
                }
                std::cout << "   Books from " << l.libraryName << " in " << l.cityName << " saved to books.txt" << std::endl;
            }
            else
            {
                throw error("Directory not found, books data not saved.");
            }
        }
        catch (error e)
        {
            std::cerr << "  " << e.errorText << std::endl;
        }

        try
        {
            std::ofstream saveUsersFile("users.txt");
            if (saveUsersFile)
            {
                for (user i : l.libraryUser)
                {
                    saveUsersFile << i.userID << " " << i.name << " " << i.lastName << std::endl;
                }
                std::cout << "   Users from " << l.libraryName << " in " << l.cityName << " saved to users.txt" << std::endl;
            }
            else
            {
                throw error("Directory not found, user data not saved.");
            }
        }
        catch (error e)
        {
            std::cerr << "  " << e.errorText << std::endl;
        }
    }
}

void borrowReturnMenu(library &l)
{
    int menuOption = 0;
    do
    {
        std::cout << R"(
  --------------   Borrow/return book   --------------
  
  1) Borrow book
  2) Return book

  0) Quit borrow/return book menu
  
    Enter your choice: )";
        std::cin >> menuOption;
        switch (menuOption)
        {
        case 1:
        {
            system("cls");
            welcome();
            long int bookIdNum, userIdNum;
            std::cout << "\n  Enter book ID: ";
            std::cin >> bookIdNum;
            bookIdNum--;
            if (bookIdNum >= 0 && bookIdNum < l.libraryBook.size())
            {
                std::cout << l.libraryBook[bookIdNum];

                if (l.libraryBook[bookIdNum].borrowed == true)
                {
                    std::cout << "  Book already borrowed.";
                }
                else
                {
                    std::cout << "  Enter user ID of user who wants to borrow a book: ";
                    std::cin >> userIdNum;
                    if (userIdNum > 0 && userIdNum < l.libraryUser.size())
                    {
                        userIdNum--;
                        std::cout << l.libraryUser[userIdNum];

                        l.libraryBook[bookIdNum].borrow(l.libraryUser[userIdNum]);
                    }
                    else
                    {
                        std::cout << "  There is no user with this ID.";
                    }
                }
            }
            else
            {
                std::cout << "  There is no book with this ID.";
            }
        }
        break;
        case 2:
        {
            system("cls");
            welcome();
            long int bookIdNum, userIdNum;
            std::cout << "\n  Enter book ID, which you want to return: ";
            std::cin >> bookIdNum;
            bookIdNum--;
            if (bookIdNum >= 0 && bookIdNum < l.libraryBook.size())
            {
                std::cout << l.libraryBook[bookIdNum];

                if (l.libraryBook[bookIdNum].borrowed == true)
                {
                    std::cout << "  Confirm user ID: ";
                    std::cin >> userIdNum;
                    if (l.libraryBook[bookIdNum].borrowedBy == userIdNum)
                    {
                        std::cout << l.libraryBook[bookIdNum].returnBook(l.libraryUser[userIdNum]);
                    }
                    else
                    {
                        std::cout << "  Wrong user ID.";
                    }
                }
                else
                {
                    std::cout << "  Book not borrowed yet.";
                }
            }
            else
            {
                std::cout << "  There is no book with this ID.";
            }
        }
        break;
        default:
            system("cls");
            welcome();
            break;
        }
    } while (menuOption != 0);
}

void openLibrary(library &l)
{
    try
    {
        std::ifstream saveLibraryFile("library.txt");
        std::string line;
        if (saveLibraryFile)
        {
            std::getline(saveLibraryFile, line);
            std::istringstream ss(line);
            ss >> l.libraryName >> l.cityName;
        }
        else
        {
            throw error("Library file error, file was not opened.");
        }
    }
    catch (error e)
    {
        std::cerr << "  " << e.errorText << std::endl;
    }

    try
    {
        std::ifstream saveBooksFile("books.txt");
        long int bID, borrowedBy;
        std::string line, title, aName, aSurname;
        bool borrowed;
        if (saveBooksFile)
        {
            int i = 0;
            while (std::getline(saveBooksFile, line))
            {
                std::istringstream ss(line);
                ss >> bID >> title >> aName >> aSurname >> borrowed;
                l.addBook(title, aName, aSurname);
                if (borrowed)
                {
                    ss >> borrowedBy;
                    l.libraryBook[i].borrowedBy = borrowedBy;
                    l.libraryBook[i].borrowed = true;
                }
                i++;
            }
        }
        else
        {
            throw error("Books file error, file was not opened.");
        }
    }
    catch (error e)
    {
        std::cerr << "  " << e.errorText << std::endl;
    }

    try
    {
        std::ifstream saveUsersFile("users.txt");
        long int uID;
        std::string line, uName, uLastName;
        if (saveUsersFile)
        {
            int i = 0;
            while (std::getline(saveUsersFile, line))
            {
                std::istringstream ss(line);
                ss >> uID >> uName >> uLastName;
                l.addUser(uName, uLastName);
                i++;
            }
        }
        else
        {
            throw error("Directory not found, user data not saved.");
        }
    }
    catch (error e)
    {
        std::cerr << "  " << e.errorText << std::endl;
    }
}

date currentDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    date d(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
    return d;
}

void gap()
{
    std::cout << std::endl <<"------------------------------------------------------------" << std::endl;
}

book &book::borrow(user &u)
{
    borrowedBy = u.userID;
    borrowed = true;
    return *this;
}

book &book::returnBook(user &u)
{
    borrowedBy = 0;
    borrowed = false;
    return *this;
}

user::user()
{
    name = "Jan";
    lastName = "Kowalski";
    userCounter();
}

user::user(std::string nam, std::string lastNam)
{
    name = nam;
    lastName = lastNam;
    userCounter();
}

void user::userCounter()
{
    userID = ++ID;
}

void user::showUserWithID()
{
    std::cout << userID << "|\t" << name << "\t\t" << lastName << std::endl;
}

date &operator++(date &d)
{
    bool leapYear = d.isLeapYear();
    if (d.day == 31 && d.month == 12)
    {
        d.day = 1;
        d.month = 1;
        d.year++;
    }
    else if (d.day == 31 && (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10))
    {
        d.day = 1;
        d.month++;
    }
    else if (d.day == 30 && (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11))
    {
        d.day = 1;
        d.month++;
    }
    else if (d.day == 28 && d.month == 2 && leapYear == false)
    {
        d.day = 1;
        d.month++;
    }
    else if (d.day == 29 && d.month == 2 && leapYear == true)
    {
        d.day = 1;
        d.month++;
    }
    else
    {
        d.day++;
    }
    return d;
}

date &operator--(date &d)
{
    bool leapYear = d.isLeapYear();
    if (d.day == 1 && d.month == 1)
    {
        d.day = 31;
        d.month = 12;
        d.year--;
    }
    else if (d.day == 1 && (d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12))
    {
        d.day = 31;
        d.month--;
    }
    else if (d.day == 1 && (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11))
    {
        d.day = 30;
        d.month--;
    }
    else if (d.day == 1 && d.month == 3 && leapYear == false)
    {
        d.day = 28;
        d.month--;
    }
    else if (d.day == 1 && d.month == 3 && leapYear == true)
    {
        d.day = 29;
        d.month--;
    }
    else
    {
        d.day--;
    }
    return d;
}

std::ostream &operator<<(std::ostream &s, const book &bookToDisplay)
{
    s << "  " << bookToDisplay.bookID << "|\t" << bookToDisplay.title << "\t\t" << bookToDisplay.authorName << " " << bookToDisplay.authorSurname << "\t\t";
    if (bookToDisplay.borrowed == true)
    {
        s << "Borrowed by: " << bookToDisplay.borrowedBy;
    }
    else
    {
        s << "Not borrowed";
    }
    s << std::endl;

    return s;
}

std::ostream &operator<<(std::ostream &s, const user &userToDisplay)
{
    s << "  " << userToDisplay.userID << "|\t" << userToDisplay.name << " " << userToDisplay.lastName << std::endl;
    return s;
}

library::library()
{
    libraryName = "Main_library";
    cityName = "Gliwice";
}

void library::libraryInfo()
{
    std::cout << "  -------------    Library info    -------------\n"
              << std::endl
              << "  Library name: \t" << libraryName << std::endl
              << "  City of library:\t" << cityName << std::endl
              << "  Number of books:\t" << numOfBooks << std::endl
              << "  Number of users:\t" << numOfUsers << std::endl;
}

void library::addBook()
{
    book a;
    libraryBook.push_back(a);
    numOfBooks++;
}

void library::addBook(std::string t, std::string an, std::string asn)
{
    book a(t, an, asn);
    libraryBook.push_back(a);
    numOfBooks++;
}

void library::showAllUsers()
{
    std::cout << "  --------------    Users list    --------------\n"
              << std::endl;
    for (auto u : libraryUser)
        std::cout << u;
}

void library::showBook(long int bID)
{
    if (bID <= libraryBook.size() && bID > 0)
    {
        std::cout << "\n"
                  << libraryBook[static_cast<std::vector<book, std::allocator<book>>::size_type>(bID) - 1];
    }
    else
    {
        std::cout << "\n  There is no book with this ID number!" << std::endl;
    }
}

void library::showUser(long int uID)
{
    if (uID <= libraryUser.size() && uID > 0)
    {
        std::cout << "\n"
                  << libraryUser[uID - 1];
    }
    else
    {
        std::cout << "\n  There is no user with this ID number!" << std::endl;
    }
}

void library::searchBook(int option, std::string searchString, std::string searchString2)
{
    switch (option)
    {
    case 2:
    {
        bool foundFlag = false;
        for (auto &b : libraryBook)
        {
            if (searchString == b.title)
            {
                std::cout << b;
                foundFlag = true;
            }
        }
        if (!foundFlag)
        {
            std::cout << "  Book " << searchString << " not found." << std::endl;
        }
    }
    break;
    case 3:
    {
        bool foundFlag = false;
        char choice = 0;
        for (auto &b : libraryBook)
        {
            if (searchString == b.authorName && searchString2 == b.authorSurname)
            {
                std::cout << b;
                foundFlag = true;
            }
        }
        if (!foundFlag)
        {
            std::cout << "  Book not found. Do you want to search only by surname? (Y/N)" << std::endl
                      << "  ";
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                for (auto &b : libraryBook)
                {
                    if (searchString2 == b.authorSurname)
                    {
                        std::cout << b;
                        foundFlag = true;
                    }
                }
            }
        }
        if (!foundFlag)
        {
            std::cout << "  Book not found." << std::endl;
        }
    }
    break;
    case 4:
    {
        bool foundFlag = false;
        for (auto &b : libraryBook)
        {
            if (b.borrowed == true)
            {
                std::cout << b;
                foundFlag = true;
            }
        }
        if (!foundFlag)
        {
            std::cout << "  Book not found." << std::endl;
        }
    }
    break;
    case 5:
    {
        bool foundFlag = false;
        for (auto &b : libraryBook)
        {
            if (b.borrowed == false)
            {
                std::cout << b;
                foundFlag = true;
            }
        }
        if (!foundFlag)
        {
            std::cout << "  Book not found." << std::endl;
        }
    }
    break;
    default:
        std::cout << "  Book not found." << std::endl;
        break;
    }
}

void library::searchUser(int option, std::string searchString, std::string searchString2)
{
    switch (option)
    {
    case 2:
    {
        bool foundFlag = false;
        for (auto &u : libraryUser)
        {
            if (searchString == u.name)
            {
                std::cout << u;
                foundFlag = true;
            }
        }
        if (!foundFlag)
        {
            std::cout << "  User " << searchString << " not found." << std::endl;
        }
    }
    break;
    case 3:
    {
        bool foundFlag = false;
        for (auto &u : libraryUser)
        {
            if (searchString == u.lastName)
            {
                std::cout << u;
                foundFlag = true;
            }
        }
        if (!foundFlag)
        {
            std::cout << "  User " << searchString << " not found." << std::endl;
        }
    }
    break;
    case 4:
    {
        bool foundFlag = false;
        char choice = 0;
        for (auto &u : libraryUser)
        {
            if (searchString == u.name && searchString2 == u.lastName)
            {
                std::cout << u;
                foundFlag = true;
            }
        }
        if (!foundFlag)
        {
            std::cout << "  User not found. Do you want to search only by surname? (Y/N)" << std::endl
                      << "  ";
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                for (auto &u : libraryUser)
                {
                    if (searchString2 == u.lastName)
                    {
                        std::cout << u;
                        foundFlag = true;
                    }
                }
            }
        }
        if (!foundFlag)
        {
            std::cout << "  User not found." << std::endl;
        }
    }
    break;
    default:
        std::cout << "  User not found." << std::endl;
        break;
    }
}

void library::showAllBooks()
{
    std::cout << "  --------------    Books list    --------------\n"
              << std::endl;
    for (auto &b : libraryBook)
        std::cout << b;
}

void library::addUser()
{
    user u;
    libraryUser.push_back(u);
    numOfUsers++;
}

void library::addUser(std::string nam, std::string lastNam)
{
    user u(nam, lastNam);
    libraryUser.push_back(u);
    numOfUsers++;
}

admin::admin()
{
    name = "Janusz";
    lastName = "Kowalski";
    username = "admin";
    password = "zaq1@WSX";
}

bool admin::login(std::string &login, std::string &psw)
{
    if (username == login && password == psw)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void admin::editBook(library &l, long int bID)
{
    if (bID <= l.libraryBook.size() && bID > 0)
    {
        int choice = 0;
        do
        {
            std::cout << "  ---------------    Edit book    --------------\n\n";
            std::cout << "\n"
                      << l.libraryBook[bID - 1] << std::endl;
            std::cout << "  Which element do you want to edit?" << std::endl;
            std::cout << R"(
  1) Book title
  2) Autor name
  3) Author surname

  0) Quit editing
    Enter your choice: )";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                std::cout << "\n  Enter new book title: ";
                std::cin >> l.libraryBook[bID - 1].title;
                system("cls");
                welcome();
                std::cout << "  ---------------    Edit book    --------------\n";
                std::cout << "\n  Title changed.\n";
            }
            break;
            case 2:
            {
                std::cout << "\n"
                          << l.libraryBook[bID - 1] << "\n  Enter author name: ";
                std::cin >> l.libraryBook[bID - 1].authorName;
                system("cls");
                welcome();
                std::cout << "  ---------------    Edit book    --------------\n";
                std::cout << "\n  Author name changed.\n";
            }
            break;
            case 3:
            {
                std::cout << "\n"
                          << l.libraryBook[bID - 1] << "\n  Enter author surname: ";
                std::cin >> l.libraryBook[bID - 1].authorSurname;
                system("cls");
                welcome();
                std::cout << "  ---------------    Edit book    --------------\n";
                std::cout << "\n  Author surname changed.\n";
            }
            break;
            default:
                break;
            }
        } while (choice != 0);
    }
    else
    {
        std::cout << "\n  There is no book with this ID number!" << std::endl
                  << "  ";
        system("pause");
    }
}

void admin::editUser(library &l, long int uID)
{
    if (uID <= l.libraryUser.size() && uID > 1)
    {
        int choice = 0;
        do
        {
            std::cout << "  --------------    Edit user    ---------------\n"
                      << std::endl;
            std::cout << "\n"
                      << l.libraryUser[uID - 1] << std::endl;
            std::cout << "  Which element do you want to edit?" << std::endl;
            std::cout << R"(
  1) User name
  2) User surname

  0) Quit editing
    Enter your choice: )";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                std::cout << "\n  Enter user name: ";
                std::cin >> l.libraryUser[uID - 1].name;
                system("cls");
                welcome();
                std::cout << "  --------------    Edit user    ---------------\n";
                std::cout << "\n  User name changed.\n\n";
            }
            break;
            case 2:
            {
                std::cout << "\n"
                          << "\n  Enter user surname: ";
                std::cin >> l.libraryUser[uID - 1].lastName;
                system("cls");
                welcome();
                std::cout << "  --------------    Edit user    ---------------\n";
                std::cout << "\n  User surname changed.\n\n";
            }
            break;
            default:
                break;
            }
        } while (choice != 0);
    }
    else
    {
        std::cout << "\n  There is no user with this ID number!" << std::endl
                  << "  ";
        system("pause");
    }
}

void admin::editLibrary(library &l)
{
    int choice = 0;
    do
    {
        system("cls");
        welcome();
        std::cout << std::endl
                  << R"(
  -------------    Edit library    -------------
  |                                            |)"
                  << std::endl;
        l.libraryInfo();
        std::cout << std::endl
                  << "  Which element do you want to edit?" << std::endl;
        std::cout << R"(
  1) Library name
  2) Library city

  0) Quit editing
    Enter your choice: )";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::cin >> l.libraryName;
        }
        break;
        case 2:
        {
            std::cin >> l.cityName;
        }
        break;
        default:
            break;
        }
    } while (choice != 0);
}

error::error()
{
    errorText = "Unknown error.";
}

date::date()
{
	day = 1;
	month = 1;
	year = 2000;
}

void date::displayDay()
{
    if(day < 10)
    {
        std::cout << "0" << day;
    }
    else
    {
        std::cout << day;
    }
}

void date::displayMonth()
{
    if(month < 10)
    {
        std::cout << "0" << month;
    }
    else
    {
        std::cout << month;
    }
}

void date::display()
{
    displayDay();
    std::cout << ".";
    displayMonth();
    std::cout << "." << year << std::endl;
}

bool date::isLeapYear()
{
    if (year % 4 == 0)
    {
        return true;
    }
    return false;
}

bool date::isValid()
{
    //Check the year or month is valid
    if (year < 0 || month < 0 || month > 12)
    {
        return false;
    }

    //Check the day is valid for the month
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && isLeapYear())
    {
        maxDay++;
    }
    if (day < 0 || day > maxDay)
    {
        return false;
    }
    return true;
}

bool date::isPast()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if (ltm->tm_year + 1900 > year)
    {
        return true;
    }
    else if (ltm->tm_year + 1900 == year)
    {
        if (ltm->tm_mon + 1 > month)
        {
            return true;
        }
        else if (ltm->tm_mon + 1 == month)
        {
            if (ltm->tm_mday > day)
            {
                return true;
            }
        }
    }
    return false;
}

bool date::isFuture()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if (ltm->tm_year + 1900 < year)
    {
        return true;
    }
    else if (ltm->tm_year + 1900 == year)
    {
        if (ltm->tm_mon + 1 < month)
        {
            return true;
        }
        else if (ltm->tm_mon + 1 == month)
        {
            if (ltm->tm_mday < day)
            {
                return true;
            }
        }
    }
    return false;
}

bool date::isToday()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if (ltm->tm_mday == day && ltm->tm_mon + 1 == month && ltm->tm_year + 1900 == year)
    {
        return true;
    }
    return false;
}
