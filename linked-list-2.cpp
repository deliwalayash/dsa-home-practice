#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class LinkedList{
    public:
    Node * Head;
    int count;
    LinkedList(){
        this->count=0;
        this->Head=nullptr;
    }

    void Addatstart(int data){
        Node *newnode=new Node(data);
        if(Head == nullptr && count ==0){
            Head=newnode;
        }
        else{
            newnode->next=Head;
            Head=newnode;
        }
        this->count++;
    }

    void AddatEnd(int data){
        Node *newnode=new Node(data);
        if(Head == nullptr && count ==0){
              Head=newnode;
        }
        else{
            Node *temp=Head;
            while(temp->next !=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
        }

        this->count++;
    }

    void addAtPos(int data,int pos){
        Node *newnode =new Node(data);
        if(Head ==nullptr && count==0){
            Head=newnode;
        }
        else{
            Node *temp=Head;
            for(int i =0;i <pos-1 ;i++){
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }

        this->count++;
    }
    void updata(int data,int pos){
         Node *temp=Head;
          for(int i =0;i <pos-1 ;i++){
                temp=temp->next;
            }
            temp->data=data;

    }

    void deleteAtStart(){
        if(Head == nullptr && count==0){
            cout <<"Linked list is empty:" << endl;
        }
        else{
            Node *temp=Head;
            Head=Head->next;
            delete temp;
            temp=nullptr;
            this->count--;

        }
    }
    void deleteAtEnd(){
        if(Head == nullptr && count==0){
            cout <<"Linked list is empty:" << endl;
            return;
        }
        if(count==1){
            this->deleteAtStart();
            this->count--;
            return;
        }
        Node *temp=Head;
        while (temp->next->next !=nullptr)
        {
            temp=temp->next;
        }
        // delete temp->next;
        temp->next = nullptr;
        this->count--;
        
    }

    void deleteAtPos(int pos){
        Node *curr=Head;
        Node *prev=Head;

        for(int i = 0;i < pos;i++){
            curr=curr->next;
        }
        for(int i = 0;i < pos -1;i++){
            prev=prev->next;
        }
        prev->next=curr->next;
        // delete curr;
        // prev = nullptr;
        this->count--; 
    }
    void Display(){
        Node *temp=Head;
        while (temp !=nullptr)
        {
            cout <<temp->data<<"->";
            temp=temp->next;
        }
        cout <<"NULL";
        cout << endl;
    }
};

int main(){

    LinkedList l1;
    int choice;
    do
    {
        cout <<"Enter 1 to Add Node At Start:" << endl;
        cout <<"Enter 2 to Add Node At End:" << endl;
        cout <<"Enter 3 to Add Node At Pos:" << endl;
        cout <<"Enter 4 to Display:" << endl;
        cout <<"Enter 5 to Delete Node At Start:" << endl;
        cout <<"Enter 6 to Delete Node At End:" << endl;
        cout <<"Enter 7 to Delete Node At Pos:" << endl;
        cout <<"Enter your Choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            {   
                int data;
                cout <<"Enter data:";
                cin >> data;
                l1.Addatstart(data);
                cout <<"Data Entered Successfully:" << endl;
                break;
            }
        case 2:
            {   
                int data;
                cout <<"Enter data:";
                cin >> data;
                l1.AddatEnd(data);
                cout <<"Data Entered Successfully:" << endl;
                break;
            }
        case 3:
            {   
                int data,pos;
                cout <<"Enter Pos \n & Data";
                cin >> pos >> data ;
                l1.addAtPos(data,pos-1);
                cout <<"Data Entered Successfully:" << endl;
                break;
            }
        case 4:
            {   
                l1.Display();
                break;
            }
         case 5:
            {   
                
                l1.deleteAtStart();
                cout <<"Data Deleted Successfully:" << endl;
                break;
            }
         case 6:
            {   
                
                l1.deleteAtEnd();
                 cout <<"Data Deleted Successfully:" << endl;
                break;
            }
         case 7:
            {   
                int pos;
                cout <<"Enter position:";
                cin >> pos;
                l1.deleteAtPos(pos);
                cout <<"Data Deleted Successfully:" << endl;
                break;
            }
        
        
        default:
            break;
        }
    } while (choice !=0);
    
}