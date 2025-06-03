#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &,int,int,int);


int main(){

    int size;
    cout <<"Enter size of array:";
    cin >> size;

    vector<int> arr(size);

    for(int i = 0; i < size;i++){
        cout <<"Enter data:";
        cin >> arr[i];
    }

    cout <<"\n-----------before-------------\n";

    for(int val:arr){
        cout << val <<" ";
    }

    for(int i = 0 ; i < arr.size()-1;i++){
        for(int j = 0 ; j < arr.size()-1-i;j++){
            if(arr[j] > arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    cout <<"\n-----------after-------------\n";

    for(int val:arr){
        cout << val <<" ";
    }

    int key;
    cout <<"Enter you want to find key:";
    cin >> key;


    int idx=binarySearch(arr,0,size-1,key);
    if(idx == -1){
        cout <<"Element not found in array:";
    }
    else{
        cout <<"Element found in array on index:" << idx;
    }

    return 0;

}

int binarySearch(vector<int> &arr,int low,int high,int key){

    if(low > high)
    return -1;

    int mid = (low + high)/2;
    if(arr[mid] == key){
        return mid;
    }

    else if(key < arr[mid]){
        return binarySearch(arr,low,mid-1,key);
    }
    else{
        return binarySearch(arr,mid+1,high,key);
    }
}