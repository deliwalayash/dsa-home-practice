#include<iostream>
#include<vector>
using namespace std;

void mergeSort(vector <int> &,int,int);
void merge(vector <int>&,int,int,int);

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

    mergeSort(arr,0,size - 1);


    cout <<"\n-------after---------\n";

    for(int i = 0 ; i < size ; i ++){
        cout << arr[i] <<" ";
    }

    return 0;

}
void mergesort(vector <int> &arr,int low,int high){

    //recursive funtion
    if(low >=high){
        return;
    }

    int mid=(low + high) / 2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);

}

void merge(vector <int>& arr,int low,int high ,int mid){

    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
             temp.push_back(arr[right]);
             right++;
        }
    }
}

