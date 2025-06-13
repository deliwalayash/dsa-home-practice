#include<iostream>
#include<stack>
using namespace std;
int main(){

    string s;
    stack<char>palindrome;
    cout <<"Enter string you want to check plaindrome:";
    cin >> s;

    for(char val:s){
        palindrome.push(val);
    }

    bool flag=1;
        for(char d:s){
            if(d!= palindrome.top() ){
                flag=0;
                cout <<"String is not palindrome:";
                break;
            }
            else{
                palindrome.pop();
            }
        }
    

    if(flag==1){
        cout <<"The Sting is Palindrome:";
    }
    
return 0;
}