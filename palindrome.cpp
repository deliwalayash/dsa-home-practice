#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){

    string s;
    stack <char>c;
    cout <<"Enter String you want to check palindrome or not:";
    cin >>s;

    for(char val:s){
        c.push(val);
    }

    bool flag=1;

    for(char val:s){
        if(val != c.top()){
             flag=0;
             break;   
        }
        c.pop();
    }

    if(flag==0){
        cout <<"the string is not palindrome:";
    }
    else{
        cout <<"the string is palindrome:";
    }
    

}