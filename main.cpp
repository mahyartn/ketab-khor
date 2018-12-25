#include "basic.h"
#include "shelfman.h"
#include "bookman.h"
#include "accounting.h"
#include "social.h"


void func(AcountingCLI account);

std::string StartMenu="what do you want to do?\n"\
"    1- SignUp\n"\
"    2- SingIn\n"\
"    3- Exit\n\n"\
"your choice: ";

std::string FunctionMenu="what do you want to do?(type in lower case)\n"\
"    a- Show All Books\n"\
"    b- Show a Book\n"\
"    c- Like a Book\n"\
"    d- Buy a Book\n"\
"    e- Show your favorite books\n"\
"    f- Show your books\n"\
"    g- Show your shelves\n"\
"    h- Show books from a shelf\n"\
"    i- Create a new shelf\n"\
"    j- Add a book to a shelf\n"\
"    k- Follow a person\n"\
"    l- Show latest Updates\n"\
"    z- Logout\n\n"\
"your choice: ";

int main()
{
    AcountingCLI account;
    bool RunningProgram=true;
    while (RunningProgram)
    {
        system ("clear");
        std::cout<<StartMenu;
        char choice;
        std::cin >> choice;  
        switch (choice) 
        {
            case '1':
            account.Register();
            break;
            case '2':
            func(account);
            break;
            case '3':
            RunningProgram=false;
            break;
            default:
            break;
        }

    }
}

void func(AcountingCLI account)
    {
    account.Login();
    BookCLI BookFuncs(*account.db,account.CurrentUser());
    ShelfCLI ShelfFuncs(*account.db,account.CurrentUser());
    SocialCLI SocialFuncs(*account.db,account.CurrentUser());
    bool LogedIn=true;
    while(LogedIn)
    {
        std::cout<<FunctionMenu;
        char choice;
        std::cin >> choice;  
        switch (choice) 
        {
            case 'a':
            BookFuncs.ShowAllBooks();
            break;
            case 'b':
            BookFuncs.ShowOneBook();
            break;
            case 'c':
            BookFuncs.LikeBook();
            break;
            case 'd':
            BookFuncs.BuyBook();
            break;
            case 'e':
            BookFuncs.ShowFavoriteBooks();
            break;
            case 'f':
            ShelfFuncs.ShowMyBooks();
            break;
            case 'g':
            ShelfFuncs.ShowShelves();
            break;
            case 'h':
            ShelfFuncs.ShowShelfBooks();
            break;
            case 'i':
            ShelfFuncs.AddShelf();
            break;
            case 'j':
            ShelfFuncs.AddToShelf();
            break;
            case 'k':
            SocialFuncs.Follow();
            break;
            case 'l':
            SocialFuncs.ShowUpdates();
            break;
            case 'z':
            LogedIn=false;
            break;
            default:
            break;
        }
    }
}
    
    // BookFuncs.ShowAllBooks();
    // BookFuncs.ShowOneBook();
    // BookFuncs.LikeBook();
    // BookFuncs.BuyBook();
    // BookFuncs.ShowFavoriteBooks();
    // ShelfFuncs.ShowMyBooks();
    // ShelfFuncs.ShowShelves();
    // ShelfFuncs.ShowShelfBooks();
    // ShelfFuncs.AddShelf();
    // ShelfFuncs.AddToShelf();
    // SocialFuncs.Follow();
    // SocialFuncs.ShowUpdates();
    // std::cout<<test.acman->current_session_id<<"jj\n";
    // MyDataBase db1("mydatabase.db");
    // AccountManager ali(db1);
    // BookFunctions books(db1);
    // ShelfFunctions shelves(db1);
    // Social comunity(db1);
    // ali.Authenticate("admin","astro321");
    // ali.AddUser("mahdi","astro321");
    // books.AllBooks();
    // books.Book("10");
    // books.LikeBook("13","mahyar");
    // books.BuyBook("1","mahyar");
    // books.FavoriteBooks("mahyar");
    // shelves.AddShelf("Fiction","mahyar");
    // shelves.AddToShelf("Fiction","mahyar","1");
    // shelves.ShowShelves("mahyar");
    // shelves.ShowShelfBooks("mahyar","Fiction");
    // shelves.ShowMyBooks("mahyar");
    // comunity.Follow("mahdi","mahyar");
    // comunity.GetLastTime("mahyar");
    // comunity.SetLastTime("mahyar");
    // comunity.GetNewLikes("mahdi","2018-12-22 00:01:59");
    // comunity.GetNewOwned("mahdi","2017-12-22 00:01:59");
    // comunity.GetNewFriends("mahdi","2017-12-22 00:01:59");
    // std::cout<<ali.Authenticate("mahyar","astro123")<<"\n";
    // }
 