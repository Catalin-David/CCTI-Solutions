#include <iostream>
#include <unordered_map>
using namespace std;

enum AccountType
{
    STANDARD, PREMIUM
};

class User
{
private:
    int userId;
    string details;
    AccountType accountType;
public:
    User(int id, string details, AccountType accountType)
    {
        this->userId = id;
        this->details = details;
        this->accountType = accountType;
    }

    int getId()
    {
        return userId;
    }
    void setId(int id)
    {
        userId = id;
    }

    string getDetails()
    {
        return details;
    }
    void setDetails(string details)
    {
        this->details = details;
    }

    AccountType getAccountType()
    {
        return accountType;
    }
    void setAccountType(AccountType type)
    {
        accountType = type;
    }
};

class Book
{
private:
    int id;
    string details;

public:
    Book(int id, string details)
    {
        this->id = id;
        this->details = details;
    }

    int getId()
    {
        return id;
    }
    void setid(int id)
    {
        this->id = id;
    }

    string getDetails()
    {
        return details;
    }
    void setDetails(string details)
    {
        this->details = details;
    }
};

class Display
{
private:
    Book* activeBook;
    User* activeUser;
    int pageNumber = 0;

public:
    void displayUser(User* user)
    {
        activeUser = user;
        refreshUsername();
    }

    void displayBook(Book* book)
    {
        pageNumber = 0;
        activeBook = book;

        refreshTitle();
        refreshDetails();
        refreshPage();
    }

    void turnPageForward()
    {
        // verify it's not the last page
        pageNumber++;
        refreshPage();
    }

    void turnPageBackwards()
    {
        if(pageNumber == 0)
        {
            // throw an error
        }
        pageNumber--;
        refreshPage();
    }

    void refreshUsername() { /* updates username display */ }
    void refreshTitle() { /* updates tite display */ }
    void refreshDetails() {/* updates details display*/}
    void refreshPage() {/* updates page display */}
};

class UserManager
{
private:
    unordered_map<int, User*> users;
public:
    User* addUser(int id, string details, AccountType accountType)
    {
        if(users.find(id) != users.end())
        {
            return nullptr;
        }

        User* user = new User(id, details, accountType);
        users[id] = user;
        return user;
    }

    User* find(int id)
    {
        return users[id];
    }

    bool remove(User* u)
    {
        return remove(u->getId());
    }

    bool remove(int id)
    {
        if(users.find(id) == users.end())
        {
            return false;
        }

        users.erase(id);
        return true;
    }
};

class Library
{
private:
    unordered_map<int, Book*> books;

public:
    Book* addBook(int id, string details)
    {
        if(books.find(id) != books.end())
        {
            return nullptr;
        }

        Book* book = new Book(id, details);
        books[id] = book;
        return book;
    }

    Book* find(int id)
    {
        return books[id];
    }

    bool remove(Book* book)
    {
        return remove(book->getId());
    }

    bool remove(int id)
    {
        if(books.find(id) == books.end())
        {
            return false;
        }

        books.erase(id);
        return true;
    }
};

class OnlineReaderSystem
{
private:
    Library* library;
    UserManager* userManager;
    Display* display;

    Book* activeBook;
    User* activeUser;

public:
    OnlineReaderSystem()
    {
        library = new Library();
        userManager = new UserManager();
        display = new Display();
    }

    Library* getLibrary()
    {
        return library;
    }
    UserManager* getUserManager()
    {
        return userManager;
    }
    Display* getDisplay()
    {
        return display;
    }

    Book* getActiveBook()
    {
        return activeBook;
    }
    void setActiveBook(Book* book)
    {
        activeBook = book;
        display->displayBook(book);
    }

    User* getActiveUser()
    {
        return activeUser;
    }
    void setActiveUser(User* user)
    {
        activeUser = user;
        display->displayUser(user);
    }
};


int main()
{

    return 0;
}
