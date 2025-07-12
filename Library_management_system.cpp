#include <iostream>
#include <string>
using namespace std;
int const MAX_BOOKS = 100;
// Updated struct to include copies and ISBN
struct books
{
    string name;
    string author;
    int copies;
    string isbn;
};
void  addbooks(books library[], int &bookcount );
void  displaybooks(books const library[], int &bookcount );
void  searchbooks(books const library[], int &bookcount );
void  deletebooks(books library[], int &bookcount );
string generate_isbn();
int main()
{
    books library [MAX_BOOKS];
    int bookcount=0;
    int choice;
    do
    {
        cout<<"\n\tLibrary Management System\t\n";
        cout<<"1. Add a book to the library\n";
        cout<<"2. Display all books in the library\n";
        cout<<"3. Search a book from the library\n";
        cout<<"4. Delete a book from the library\n";
        cout<<"5. Exit program\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1: addbooks(library, bookcount);
            break;
        case 2: displaybooks(library, bookcount);
            break;
        case 3: searchbooks(library,  bookcount);
            break;
        case 4: deletebooks(library, bookcount);
            break;
        case 5:cout<<"Exited Successfully"; break;                                
        default:cout<<"Invalid";
            break;
        }
    } while (choice !=5 );
    
    return 0;
}
void addbooks(books library[], int &bookcount)
{
    if (bookcount>=MAX_BOOKS)
    {
        cout<<"The library has reached its limit!";
        return;
    }
    cout<<"Enter the name of the book: ";
    cin.ignore();
    getline(cin, library[bookcount].name);
    cout<<"Enter the author's name: ";
    getline(cin, library[bookcount].author);
    cout<<"Enter the number of copies: ";
    cin >> library[bookcount].copies;
    cin.ignore();
    library[bookcount].isbn = generate_isbn();
    cout << "Generated ISBN (13-digit): " << library[bookcount].isbn << endl;
    bookcount++;
}
void displaybooks(const books library[], int &bookcount)
{
    if (bookcount==0)
    {
        cout<<"There are no books in the library!";
        return;
    }
    for (int i = 0; i < bookcount; i++)
    {
        cout<<i+1 << ". " <<library[i].name<<" by "<<library[i].author;
        cout<<" | Copies: " << library[i].copies;
        cout<<" | ISBN: " << library[i].isbn << endl;
    }
}
void searchbooks(const books library[], int &bookcount)
{
    if (bookcount==0)
    {
        cout<<"There are no books in the library!";
        return;
    }
    string searchname;
    cout<<"Enter the name of the book: ";
    cin.ignore();
    getline(cin, searchname);
    bool found = false;
    for (int i = 0; i < bookcount; i++)
    {
        if (searchname==library[i].name)
        {
            cout<<"Found in "<<i+1<< " row of the shelf "<<endl;
            cout<<library[i].name<<" by "<<library[i].author;
            cout<<" | Copies: " << library[i].copies;
            cout<<" | ISBN: " << library[i].isbn << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Book not found!";
    }
}
void deletebooks(books library[], int&bookcount)
{
    string deletebook;
    cout<<"Enter the name of the book you want to delete: ";
    cin.ignore();
    getline(cin, deletebook);

    if (bookcount==0)
    {
        cout<<"There are no books to be deleted!";
        return;
    }
    for (int i = 0; i < bookcount; i++)
    {
        if (deletebook==library[i].name)
        {
            for (int j = i; j < bookcount-1; j++)
            {
                library[j]=library[j+1];
            }
            bookcount--;
            cout<<"Book Deleted successfully";
            return;
        }
    }
    cout << "Book not found!";
}
// Function to generate a random 13-digit ISBN
#include <ctime>
#include <cstdlib>
string generate_isbn() {
    string isbn = "";
    srand((unsigned)time(0) + rand());
    for (int i = 0; i < 13; i++) {
        isbn += to_string(rand() % 10);
    }
    return isbn;
}