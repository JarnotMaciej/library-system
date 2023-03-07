/**
 * @file functions.h
 * @author Maciej Jarnot (mj300741@student.polsl.pl)
 * @brief Library system
 * @version v2
 * @date 07.03.2023
 *
 */

#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>

class date;
class error;
class book;
class user;
class library;
class admin;

/** Class used for indicating errors in the program
 */
class error
{
public:
    std::string errorText;
    /** Default constructor
     * errorText = "Unknown error"
     */
    error();
    /** Contructor with string to change
     * @errorText - error text
     */
    error(std::string m) : errorText(m){};
};

/** Class used for handling dates
 * Date is represented by day, month and year
 */
class date
{
    int day;   /**< Day of the date*/
    int month; /**< Month of the date*/
    int year;  /**< Year of the date*/

public:
    /** Default constructor
     * day = 1;
     * month = 1;
     * year = 2000;
     */
    date();

    /** Constructor with parameters
     * @param d - day
     * @param m - month
     * @param y - year
     */
    date(int d, int m, int y) : day(d), month(m), year(y)
    {
        if (!isValid())
        {
            throw error("Invalid date");
        }
    };

    /** Destructor
    */
    ~date(){}; //destructor

    /** Method which displays day
     */
    int displayDay();

    /** Method which displays month
     */
    int displayMonth();

    /** Method which displays year
     */
    int displayYear();

    /** Method which displays date
     */
    void display();

    /** Method which chcecks if the year is leap
     */
    bool isLeapYear();

    /** Method which checks if date is valid
     */
    bool isValid();

    /** Method which checks if date is in the past
     */
    bool isPast();

    /** Method which checks if date is in the future
     */
    bool isFuture();

    /** Method which checks if date is today
     */
    bool isToday();

    /** friend, increment operator
     */
    friend date &operator++(date &d);

    /** friend, decrement operator
     */
    friend date &operator--(date &d);

    /** friend, operator used to display date
     */
    friend std::ostream &operator<<(std::ostream &s, const date &d);

    /** friend, operator used to enter date
    */
    friend std::istream &operator>>(std::istream &s, date &d);

    /** friend, operator used to add days to date
    */
    friend date &operator+(date &d, int days);

    /** friend, operator used to subtract days from date
    */
    friend date &operator-(date &d, int days);

    /** friend, operator used to subtract date from date
    */
    friend int operator-(date &d1, date &d2);

};

/** Class which represents book element in library
 */
class book
{
    std::string title;         /**< Book title*/
    std::string authorName;    /**< Name of the author of the book*/
    std::string authorSurname; /**< Surname of the author of the book*/
    bool borrowed;             /**< Indication if book is borrowed or not*/
    long int borrowedBy;       /**< ID of user, who borrowed book*/
    static long int ID;        /**< Counter of IDs*/
    long int bookID;           /**< Primary key, unique ID of book*/
    date borrowedDate;         /**< Date of borrowing book*/
    bool expired;              /**< Indication if book is expired or not*/

public:
    /** Default book constructor
     * 	title = "no-title";
     *	authorName = "no-author-name";
     *	authorSurname = "no-author-surname";
     */
    book();

    /** Book constructor
     * @param t - book title
     * @param an - author name
     * @param asn - author surname
     */
    book(std::string t, std::string an, std::string asn);
    // void display();

    /** Method assigns user ID and date of borrowing to book
     */
    book &borrow(user &u);

    /** Method which checks if current user can return the book, and if yes - it allows to do it
     */
    book &returnBook(user &u);

    /** Method which checks if the book ius expired*/
    bool isExpired(int days);

    friend std::ostream &operator<<(std::ostream &s, const book &bookToDisplay);
    friend void saveLibrary(const library &l);
    friend void openLibrary(library &l);
    friend class user;
    friend class library;
    friend class admin;
    friend void borrowReturnMenu(library &l);
};
// long int book::ID = 0;

/** Book operator, which displays data of the book
 */
std::ostream &operator<<(std::ostream &s, const book &bookToDisplay);

/** Class which represents users of library
 */
class user
{
    std::string name;     /**< User name*/
    std::string lastName; /**< User surname*/
    static long int ID;   /**< Counter of users*/
    long int userID;      /**< Unique ID of user*/
                          // std::list <book*> borrowedBooks; /**< List of borrowed books pointers by user*/
public:
    /** Default user constructor
     * 	name = "Jan";
     *   lastName = "Kowalski";
     */
    user();

    /** User constructor
     * 	@param nam = name
     *	@param lastNam = surname
     */
    user(std::string nam, std::string lastNam);

    /** Function used for user counting
     */
    virtual void userCounter();

    /** Method which dispplays user information with ID
     */
    void showUserWithID();

    friend std::ostream &operator<<(std::ostream &s, const user &userToDisplay);
    friend void saveLibrary(const library &l);
    friend void openLibrary(library &l);
    friend class book;
    friend class library;
    friend class admin;
};

/** User operator, which displays data of the user
 */
std::ostream &operator<<(std::ostream &s, const user &userToDisplay);

/** Class which represents library
 */
class library
{
    std::string libraryName;       /**< Library name*/
    std::string cityName;          /**< City where library is placed*/
    std::vector<user> libraryUser; /**< Vector of users*/
    std::vector<book> libraryBook; /**< Vector of books*/
    static long int numOfBooks;    /**< Book counter*/
    static long int numOfUsers;    /**< User counter*/
    int lengthOfBorrow;            /**< Length of borrow in days*/

public:
    /** Default book constructor
     * 	libraryName = "Main library"
     *	cityName = "Gliwice"
     *  lengthOfBorrow = 14
     */
    library();

    /** Method displays information about library
     */
    void libraryInfo();

    /** Method which add book to library (constructor with no parameters)
     */
    void addBook();

    /** Method which add book to library. It adds the book with entered parameters.
     * @param t - book title
     * @param an - author name
     * @param asn - author surname
     */
    void addBook(std::string t, std::string an, std::string asn);

    /** Method which displays all books in the library
     */
    void showAllBooks();

    /** This method let adding user to the library (constructor with no parameters)
     */
    void addUser();

    /** This method let adding user to the library
     * 	@param nam = name
     *	@param lastNam = surname
     */
    void addUser(std::string nam, std::string lastNam);

    /** Method which displays all users in the library
     */
    void showAllUsers();

    /** Method which display book by given ID
     * @param bID - ID of book which will be displayed
     */
    void showBook(long int bID);

    /** Method which display user by given ID
     * @param uID - ID of user
     */
    void showUser(long int uID);

    /** Method used for book searching
     * @param option - mode of searching (2 - book name, 3 author, 4 - borrowed, 5 - not borrowed)
     * @param searchString - string to search
     * @param searchString2 - another param to search, used in author search
     */
    void searchBook(int option, std::string searchString = "", std::string searchString2 = "");

    /** Method used for book searching
     * @param option - mode of searching (2 - search by name, 3 - search by surname, 4 seacrh by name and surname)
     * @param searchString - string to search
     * @param searchString2 - another param to search, used in author search
     */
    void searchUser(int option, std::string searchString = "", std::string searchString2 = "");

    friend void saveLibrary(const library &l);
    friend void openLibrary(library &l);
    friend class admin;
    friend void borrowReturnMenu(library &l);
};

class admin : public user
{
    std::string username; /**< Admin username*/
    std::string password; /**< Admin password*/

public:
    /** Default admin constructor
     * 	name = "Jan";
     *   lastName = "Kowalski";
     *	username = "admin";
     *	password = "zaq1@WSX";
     */
    admin();

    /** Method which checks if the login and password are correct
     * @param login - login
     * @param psw - password
     */
    bool login(std::string &login, std::string &psw);

    /** Method which allows to edit book in given library
     * @param l - library in which we edit the book
     * @param bID - book to edit, ID of the book is used
     */
    void editBook(library &l, long int bID);

    /** Method which allows to edit user in given library
     * @param l - library in which we edit the user
     * @param uID - user to edit, ID of the user is used
     */
    void editUser(library &l, long int uID);
    // wprowadzic do 2 funkcji powyzej ify (czy ksiazka i user istnieje)

    /** Method used for editing library information
     * @param l - library to edit
     */
    void editLibrary(library &l);
};

/** Function which shows a big text: "Library System"
 */
void welcome();

/** Function shows main menu used for library operations
 * @param l - library to handle
 * @param a - admin needed for some actions
 */
void menu(library &l, admin &a);

/** Function shows menu to find some book
 * @param l - library to handle
 */
void displayBookMenu(library &l);

/** Function shows menu which helps to find a user
 * @param l - library to handle
 */
void displayUserMenu(library &l);

/** Displays admin panel used for editing library, books or users
 */
void adminPanel(library &l, admin &a);

/** A little description what the program does
 */
void aboutApp();

/** Function which saves library class to external txt file
 */
void saveLibrary(const library &l);

/** Functon which allows to borrow and to return books to library
 */
void borrowReturnMenu(library &l);

/** Function which creates library from files
 * @l - library which is modified
 */
void openLibrary(library &l);

/** Function which returns current date
 */
date currentDate();

/** Function used for debugging, it prints a line of dashes
 */
void gap();

#endif // !FUNCTIONS_H