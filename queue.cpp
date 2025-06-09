#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size;
    int count;

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
            cout<<"Queue is full:" << endl;
            return ;
        }
        if(this->front==-1 & this->rear==-1){
            this->front++;
            this->rear++;
            this->arr[this->rear]=data;
            this->count++;
        }
        else{
            this->rear++;
            this->arr[this->rear]=data;
            this->count++;
        }

    }

    void Deque(){
        if(this->count ==0 ){
            cout <<"Stack is empty:";
        }

        if(this->front == this->rear){
            this->arr[this->rear]=0;
            this->front=-1;
            this->rear=-1;
            this->count=0;
        }
        else{
            this->arr[this->front]=0;
            this->front++;
            this->count--;
        }
    }
    void Display(){
        for(int i = this->front ; i <=this->rear;i++){
            cout << arr[i];
        }
    }

    bool isfull(){
        if(this->count == this->size-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isempty(){
        if(this->count == 0){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){

     int size;
    int choice;
    cout <<"Enter size of Queue" << endl;
    cin  >> size;

    Queue q1(size);

     do
    {
        cout << "Enter 1 to Enque data:" << endl;
        cout << "Enter 2 to Deque data:" << endl;
        cout << "Enter 3 to Display data:" << endl;
        cout << "Enter 4 to queue is Full:" << endl;
        cout << "Enter 5 to queue is Empty:" << endl;
        cout << "Enter 0 to exit" << endl;
        cout <<"Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter Data:" << endl;
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
        case 4:
        {
            if(q1.isfull()==true){
                cout <<"The queue is full"<< endl;
            }
            else{
                cout <<"The queue is not full:"<< endl;
            }
            break;
        }
        case 5:
        {
            if(q1.isempty()==true){
                cout <<"The queue is Empty"<< endl;
            }
            else{
                cout <<"The queue is not Not Empty:"<< endl;
            }
            break;
        }
    }

}while(choice !=0);

return 0;
}