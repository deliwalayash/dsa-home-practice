#include<iostream>
using namespace std;

class Queue{
    private:
    int *arr;
    int front;
    int rear;
    int count;
    int size;
    public:
    Queue(int size){
        this->arr=new int[size];
        this->front=-1;
        this->rear=-1;
        this->count=0;
        this->size=size;
    }
    void Enque(int data){
        if(this->count == this->size){
            cout<<"Queue is Full:" << endl;
            return;
        }
        if(this->front==-1 && this->rear==-1){
            this->front++;
            this->rear++;
            this->arr[this->rear]=data;
            this->count++;
            cout <<"Data Entered SuccessFully:" << endl;
        }
        else{
            this->rear++;
            this->arr[this->rear]=data;
            this->count++;
            cout <<"Data Entered SuccessFully:" << endl;
        }
    }
    void Deque(){
        if(this->count==0){
            cout <<"Queue is empty:" << endl;
            return;
        }
        if(this->front == this->rear){
            this->arr[this->rear]=0;
            this->front=-1;
            this->rear=-1;
            this->count--;
            cout <<"Data Deleted SuccessFully:" << endl;
        }
        else{
            this->arr[this->front]=0;
            this->front++;
            this->count--;
             cout <<"Data Deleted SuccessFully:" << endl;
        }
    }
    void Display(){
       
        if(this->count ==0){
            cout <<"Queue is Empty" << endl;
            return;
        }
         cout <<"\n---------Queue-------\n";
        for(int i=this->front ; i <=this->rear ; i++){
            cout << arr[i] <<" ";
        }
        cout <<"\n---------Queue-------\n";
    }
};

int main(){
    int size;
    cout <<"Enter the size of Queue:";
    cin >> size;
    Queue q1(size);
    int choice;

    do
    {
        cout<<"Enter 1 to Enqueue:" << endl;
        cout<<"Enter 2 to Dequeue:" << endl;
        cout<<"Enter 3 to Display:" << endl;
        cout<<"Enter your Choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            
            {   
                int data;
                cout <<"Enter data you want to insert in the queue:";
                cin >> data;
                q1.Enque(data);
                break;
            }
        case 2:
            
            {   
              
                q1.Deque();
                break;
            }
        case 3:
            {   
              
                q1.Display();
                break;
            }
        
        default:
            break;
        }
    } while (choice !=0);
    
}