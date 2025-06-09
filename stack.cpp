#include<iostream>
#include<vector>
using namespace std;
class Stack{
    private:
    int *arr;
    int size;
    int top;
    int count;

    Stack(int size){
        this->arr=new int[size];
        this->top=-1;
        this->count=0;
        this->size=size;

    }
    void push(int data){
        this->top++;
        this->arr[top]=data;
        this->count++;
    }
    void pop(){
        arr[this->top]=0;
        this->top--;
        this->count--;
    }
    void peep(){
       cout << "Top data of stack is : "<<this->arr[top];
    }
    void Display(){
        for(int i = this->top ; i >=0;i--){
            cout << arr[i] <<" ";
        }
        cout << endl;
    }
};