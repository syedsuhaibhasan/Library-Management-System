#include <iostream>
#include <string>
using namespace std;
int const MAX_BOOKS = 100;
struct books
{
    string name;
    string author;
    string unique_number;
};
void  addbooks(books library[], int &bookcount );
void  displaybooks(books const library[], int &bookcount );
void  searchbooks(books const library[], int &bookcount );
void  deletebooks(books library[], int &bookcount );
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
        cout<<"The library has reached it's limit!";
        return;
    }
    cout<<"Enter the name of the book: ";
    cin.ignore();
    getline(cin, library[bookcount].name);
    cout<<"Enter the author's name: ";
    getline(cin, library[bookcount].author);
    cout<<"Enter the unique book number: ";
    getline(cin, library[bookcount].unique_number);
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
        cout<<endl;
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
    cout<<"Enter the name of the book:";
    cin.ignore();
    getline(cin, searchname);
    bool found = false; 
    for (int i = 1; i <= bookcount; i++)
    {
        if (searchname==library[i].name)
        {
            cout<<"Found in "<<i<< " row of the shelf "<<endl<<library[i].name<<" by "<<library[i].author;
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
    cout<<"Enter the name of the book you want to delete:";
    cin.ignore();
    getline(cin, deletebook);

    if (bookcount==0)
    {
        cout<<"There are no books to be deleted!";
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
        } 
    }
}