#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Linkedlist
{
public:
    int count;
    Node *head;
    Linkedlist()
    {
        this->count = 0;
        this->head = nullptr;
    }
    void addAtStart(int data)
    {
        Node *newnode = new Node(data);
        if (this->count == 0 && head == nullptr)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        this->count++;
    }
    void addAtEnd(int data)
    {
        Node *newnode = new Node(data);
        if (this->count == 0 && head == nullptr)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        this->count++;
    }
    void addAtPos(int data, int pos)
    {
        Node *newnode = new Node(data);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        this->count++;
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << "NULL";
        cout << endl;
    }
    void deleteAtstart()
    {
        Node *temp = head;
        head = head->next;
        
        this->count--;
    }
    void deleteAtPos(int pos)
    {
        if (pos == 1)
        {
            this->deleteAtstart();
        }
        Node *prev = head;
        Node *curr = head;
        for (int i = 1; i < pos - 1; i++)
        {
            prev = prev->next;
        }
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
        prev->next = curr->next;
      
        this->count--;
    }
    void Update(int data, int pos)
    {
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->data = data;
    }
};
class Queue{
    private:
    int *arr;
    int front;
    int rear;
    int count;
    int size;
    public:
    Queue(int size){
        this->arr=new int [size];
        this->front=-1;
        this->rear=-1;
        this->count=0;
        this->size=size;
    }
    void Enque(int data){
        if(this->count == this->size ){
            cout <<"Queue is Full:" << endl;
            return;
        }

        if(this->front ==-1 && this->rear == -1){
            this->front++;
            this->rear++;
            this->arr[this->rear]=data;
            cout <<"Data Entered Successfully:" << endl;
        }
        else{
            this->rear++;
            this->arr[this->rear]=data;
            cout <<"Data Entered Successfully:" << endl;
        }
        this->count++;
    }

    void Deque(){
        if(this->count == 0){
            cout <<"Queue is Empty:";
            return;
        }

        if(this->front == this->rear){
            this->arr[this->rear]=0;
            this->front=-1;
            this->rear=-1;
        }
        else{
            this->arr[this->front]=0;
            this->front++;
        }
    }
    void showfront(){
        cout <<"First data is" << this->arr[this->front];
        cout << endl;
    }
    void showrear(){
        cout <<"Last data is " << this->arr[this->rear];
        cout << endl;
    }
    void display(){
        if(this->count == 0){
            cout <<"Queue is Empty:";
        }
        
        for(int i = this->front ; i <= this->rear ; i++){
            cout << arr[i] <<"-->";
        }
        cout << endl;
    }
};
void mergeSort(vector<int> &,int ,int);
void merge(vector<int> &,int ,int,int);

void mergeSort(vector<int> &arr,int low,int high){
    if(low >=high){
        return;
    }
    int mid=(low + high) /2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void merge(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while (left <= mid && right <= high)
    {
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low;i <=high;i++){
        arr[i]=temp[i - low];
    }

    
}
int main()
{

    int choice;
    do
    {
        cout << "Enter 1 for Linkedlist:" << endl;
        cout << "Enter 2 for Queue:" << endl;
        cout << "Enter 3 for Mergesort:" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1: {
            Linkedlist l1;
            int choice2;
            do
            {
                cout << "Enter 1 for Add at start:" << endl;
                cout << "Enter 2 for Add at end:" << endl;
                cout << "Enter 3 for Add at pos:" << endl;
                cout << "Enter 4 for Display:" << endl;
                cout << "Enter 5 for delete at pos:" << endl;
                cout << "Enter 6 for Update Data at pos:" << endl;
                cout << "Enter your choice:";
                cin >> choice2;
                switch (choice2)
                {
                case 1:

                {
                    int data;
                    cout << "Enter Data you want to insert:";
                    cin >> data;
                    l1.addAtStart(data);
                    cout << "Data Entered Successfully:" << endl;
                    break;
                }

                case 2:

                {
                    int data;
                    cout << "Enter Data you want to insert:";
                    cin >> data;
                    l1.addAtEnd(data);
                    cout << "Data Entered Successfully:" << endl;
                    break;
                }
                case 3:

                {
                    int data;
                    cout << "Enter Data you want to insert:";
                    cin >> data;
                    int pos;
                    cout << "Enter Pos :";
                    cin >> pos;
                    l1.addAtPos(data, pos);
                    cout << "Data Entered Successfully:" << endl;
                    break;
                }
                case 4:

                {

                    l1.display();
                    break;
                }
                case 5:

                {
                    int pos;
                    cout << "Enter Pos :";
                    cin >> pos;
                    l1.deleteAtPos(pos);
                    cout << "Data Deleted Successfully:" << endl;
                    break;
                }
                case 6:

                {
                    int data;
                    cout << "Enter Data you want to insert:";
                    cin >> data;
                    int pos;
                    cout << "Enter Pos :";
                    cin >> pos;
                    l1.Update(data, pos);
                    cout << "Data Updated Successfully:" << endl;
                    break;
                }

                default:
                    break;
                }
            } while (choice2 != 0);
            break;
        }
        case 2:{
             int size;
            cout <<"Enter size of Queue";
            cin >> size;
            int choice3;

            Queue q1(size);

            do
            {
            cout <<"Enter 1 to Enque" << endl;
            cout <<"Enter 2 to Deque" << endl;
            cout <<"Enter 3 to Display" << endl;
            cout <<"Enter 4 to show front data" << endl;
            cout <<"Enter 5 to show last data" << endl;
            cout <<"Enter your choice:";
            cin >> choice3;
            switch (choice3)
            {
            case 1:
                
                {   
                    int data;
                    cout <<"Enter data:";
                    cin >> data;
                    q1.Enque(data);
                    break;
                }
            case 2:
                
                {   
                
                    q1.Deque();
                    cout <<"Data Deleted Successfully:" << endl;
                    break;
                }
            case 3:
                
                {   
                
                    q1.display();
                    break;
                }
            case 4:
                
                {   
                
                    q1.showfront();
                    break;
                }
            case 5:
                
                {   
                
                    q1.showrear();
                    break;
                }
            
            default:
                break;
            }

            } while (choice3 !=0);
                }
        case 3:{
             int size;
    cout <<"Enter size of array:";
    cin >> size;
    vector <int>arr(size);

    for(int i = 0;i < size;i++){
        cout <<"Enter data:";
        cin >> arr[i];
    }

    cout <<"\n-------before-------\n";
    for(int val:arr){
        cout << val <<" ";
    }

    mergeSort(arr,0,size - 1);

    cout <<"\n-------after--------\n";

    for(int val:arr){
        cout << val <<" ";
    }

    cout << endl;     

            
        }
                default:
                    break;
                }
        
    } while (choice != 0);
}