#include<iostream>
#include<vector>
using namespace std;


void  mergeSort(vector<int>&arr,int,int);
void  merge (vector<int>&arr,int low,int mid,int high);
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


    mergeSort(arr,0,size-1);

    cout <<"\n-------after---------\n";

    for(int i = 0 ; i < size ; i ++){
        cout << arr[i] <<" ";
    }

    return 0;

}
void  mergeSort(vector<int>&arr,int low,int high){
    if (low >=high)
    return;

    int mid = (low + high) /2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void merge(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;

    while(left <=mid && right <=high){
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


     for(int i = low;i <= high;i++){
        arr[i]=temp[i - low];
     }
}
