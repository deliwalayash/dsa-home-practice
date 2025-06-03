#include<iostream>
#include<vector>

using namespace std;

void insertionsort(vector<int> &);

int main(){

    int size;
    cout <<"Enter size of array:";
    cin >> size;

    vector<int> arr(size);

    for(int i = 0 ; i < size ; i ++){
        cout << "Enter Data:";
        cin >> arr[i];

    }

    for(int i = 0;i <= 5; i ++)

    cout <<"\n-------before---------\n";

    for(int i = 0 ; i < size ; i ++){
        cout << arr[i] <<" ";
    }


    insertionsort(arr);

    cout <<"\n-------after---------\n";

    for(int i = 0 ; i < size ; i ++){
        cout << arr[i] <<" ";
    }

    return 0;
}

void insertionsort(vector<int> &arr){
    for(int i = 1;i < arr.size() ; i++){
        int j = i-1;
        int key=arr[i];
        while(j >=0 && key < arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;

    }

}

