#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack <int> binary;
    int num;
    cout <<"Enter number you want to convert in binary:";
    cin >> num;

    while(num > 0){
        int rem= num %2;
        binary.push(rem);
        num=num/2;
    }

    while (binary.empty() == 0)
    {
        cout << binary.top();
        binary.pop();
    }
    
}