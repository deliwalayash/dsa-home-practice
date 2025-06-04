#include<iostream>
#include<vector>
using namespace std;

void selectionsort(vector <int> &);

int main(){

    int size;
    cout <<"Enter size of array:";
    cin >> size;

    vector<int> arr(size);

    for(int i = 0 ; i < size ; i ++){
        cout << "Enter Data:";
        cin >> arr[i];
    }

    cout <<"\n-------before---------\n";

    for(int i = 0 ; i < size ; i ++){
        cout << arr[i] <<" ";
    }

  
    selectionsort(arr);
 

    cout <<"\n-------after---------\n";

    for(int i = 0 ; i < size ; i ++){
        cout << arr[i] <<" ";
    }

    return 0;

}

void selectionsort(vector <int> &arr){
    for(int i = 0;i < arr.size();i++){
        int minidx=i;
        for(int j=i+1;j < arr.size();j++){
            if(arr[j] < arr[minidx] ){
                minidx=j;
            }
            
        }
        swap(arr[i],arr[minidx]);
        
    }
}



