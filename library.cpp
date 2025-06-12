#include<iostream>
#include<vector>
using namespace std;

class Book{
    protected:
    int bookId;
    string name;
    string author_name;
    bool isIssued;

    public:
    Book(){
        this->bookId=0;
        this->name="";
        this->author_name="";
        this->isIssued=false;
    }
    void addBook(int id,string name,string author_name){
        this->bookId=id;
        this->name=name;
        this->author_name=author_name;
    }
    void showBook(){
        cout<<"\n--------Book List------\n";
        cout <<"Book Id is:" << this->bookId << endl;
        cout <<"Book Name is:" << this->name << endl;
        cout <<"Book Author Name is:" << this->author_name << endl;
        cout <<"Book Availability is "<< (isIssued ? " Not Available" : "Available") << endl;
    }
    int getBookID(){
        return this->bookId;
    }

    bool getBookStatus(){
        return this->isIssued;
    }
};

class IssueBook:public Book{
    protected:
    string name;
    string date;
    public:
    IssueBook(){
        this->name="";
        this->date="";
    }
    void issuedbook(string name,string data){
        this->name=name;
        this->date=date;
        this->isIssued=true; 
        cout <<"Book isissued Sucessfully:"; 
    }
    void returnBook(){
        this->isIssued=false;
        cout <<"Book Returned Successfully:";
    }

};

int main(){

    vector<IssueBook> library;


    int choice;
    do
    {
        cout <<"Enter 1 to add book"<< endl;
        cout <<"Enter 2 to show book"<< endl;
        cout <<"Enter 3 to isssued book"<< endl;
        cout <<"Enter 4 to return book"<< endl;
        cout <<"Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            
           {
     
            int bookid;
            string name,author_name;
            cout <<"Enter Book id:";
            cin>>bookid;

            cin.ignore();
            cout <<"Enter Book Name:";
            cin >>name;

            cout <<"Enter Book Author Name:";
            cin >>author_name;
            IssueBook newBook;
            newBook.addBook(bookid, name, author_name);
            library.push_back(newBook);
            break;
            }
          
            
        case 2:
        {
            int n=library.size();
            for(int i=0;i < n;i++){
                library[i].showBook();
            }
            break;
        }
        case 3:
        {
            string name;
            string date;
            int id;
            bool flag=true;
            cout <<"Enter Book Id you want to issue:";
            cin >> id;

            for(int i = 0;i <library.size() ; i++){
                if(id == library[i].getBookID()){

                    bool flag=false;
                    if(library[i].getBookStatus()==false)
                   { 
                    cout <<"Enter your name:";
                    cin >> name;
                    cout <<"Enter date:";
                    cin >> date;
                    library[i].issuedbook(name,date);
                    }
                    else{
                        cout <<"Opps,Book is Already Issued:" << endl;
                    }
                }
            }
            if(flag==true){
                cout <<"Enter Correct Bookid:";
            }
            break;
        }
        case 4:
        {
            int id;
            cout <<"Enter Book id you want to return the book:";
            cin >> id;
            int n=library.size();
            bool flag=false;
            for(int i=0;i < n;i++){
                if(id == library[i].getBookID()){
                    flag=true;
                    if(library[i].getBookStatus()== true){
                        library[i].returnBook();
                        
                    }
                    else{
                        cout <<"Book already available so can not be returned";
                    }

                }
            }
            if(flag == false){
                cout <<"Enter correct book id:";
            }
        }

        
        default:
            break;
        }

    } while (choice !=0);  
    
    return 0;
}