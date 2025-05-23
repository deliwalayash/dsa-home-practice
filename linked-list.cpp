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


class Linkedlist{
    public:
    int count;
    Node *head;
    Linkedlist(){
        this->count=0;
        this->head=nullptr;
    }

    void Addatstart(int data){

         Node * newnode = new Node(data);
        if(head == nullptr && count == 0){
            head = newnode;
        }
        else{
            newnode->next=head;
            head = newnode;
        }
        this->count++;
    }

    void AddatEnd(int data){
        
         Node * newnode = new Node(data);
           if(head == nullptr && count == 0){
            head = newnode;
            }
            else{
                Node *temp=head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next=newnode;
            }
             this->count++;
    }

    void Display(){

        Node * temp=head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout <<endl;

    }
    void AddatPos(int data,int pos){

         Node * newnode = new Node(data);
         Node * temp=head;

        for(int i = 0 ; i < pos - 1 ; i++){
            temp = temp->next;
        }

        newnode->next=temp->next;
        temp->next=newnode;
        this->count++;

    }
    void Update(int data,int pos){

        Node *temp = head;
          for(int i = 0 ; i < pos - 1 ; i++){
            temp = temp->next;
        }
        temp->data=data;

    }

    void DeleteAtStart(){

        Node * temp=head;
        head = head->next;
        delete temp;
        temp = nullptr;
        this->count--;
        
    }
    void DeleteatEnd(){

        Node *temp=head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }

       delete temp->next;
       temp->next = nullptr;

      this->count--;

    }
};
int main(){

    int choice;
    Linkedlist l1;

    do
    {
        cout <<"Enter 1 For Add Data At Start:" <<endl;
        cout <<"Enter 2 for Add data at End:" << endl;
        cout <<"Enter 3 for Display data:" << endl;
        cout <<"Enter 4 to Enter Data at Any Position:" << endl;
        cout <<"Enter 5 to Update Data:" << endl;
        cout <<"Enter 6 to Delete At Start:" << endl;
        cout <<"Enter 7 to Delete At End:" << endl;
        cout <<"Enter Your Choice:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            
            {
                int data;
                cout <<"Enter you data:";
                cin >> data;
                l1.Addatstart(data);
                break;
            }
        case 2:
            
            {
                int data;
                cout <<"Enter you data:";
                cin >> data;
                l1.AddatEnd(data);
                break;
            }
        case 3:
            
            {
                l1.Display();
                break;
            }
        case 4:
            {
            int data,pos;
            cout <<"Enter Data and Position:";
            cin >> data >> pos;
            l1.AddatPos(data,pos);
            break;
            }
        case 5:
            {
            int data,pos;
            cout <<"enter Revised Data:" << endl;
            cin >> data;
            cout <<"Enter Position :" << endl;
            cin >> pos;
            l1.Update(data,pos);
            break;        
            }
        case 6:
        {
            l1.DeleteAtStart();
            break;
        }
        case 7:
            {
              l1.DeleteatEnd();  
              break;
            }
        
        default:
            break;
        }
    } while (choice != 0);
    
    
}