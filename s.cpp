#include<iostream>
// #include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter String:";
    cin>>s;
    int count = 1;

    for(int i =0;i < s.size() ; i++){
        if(s[i] <'a'){
            count++;
        }
    }

    cout<< count;
    return 0;
}