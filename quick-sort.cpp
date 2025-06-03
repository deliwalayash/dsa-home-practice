#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void quickSort(vector<int>&, int ,int);
int partition(vector<int>&, int , int);
void display(vector<int>&);
int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100;
    }

 display(arr);
 quickSort(arr, 0, n - 1);
 display(arr);
return 0;
}
void quickSort(vector<int>&arr, int start,int end){
     if(start >= end){
        return;
    }

    int pivotIdx = partition(arr, start, end);
    quickSort(arr, start, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, end);
}

int partition(vector<int>& arr, int start ,int end){
   
    int pivot = arr[start];
    int count = 0 , temp;

    for(int i = start; i <= end; i++){
        if(arr[i] < pivot){
            count++;
        }
    }

    int pIdx = start + count;
   
    temp = arr[start];
    arr[start] = arr[pIdx];
    arr[pIdx] = temp;
    int left = start;
    int right = end; 
    
    while(left < pIdx && right > pIdx){
        while(arr[left] < pivot){
            left++;
        }
        while(arr[right] > pivot){
            right--;
        }

       if(left < pIdx && right > pIdx){
 
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
       }
    }
    return pIdx;
}
void display(vector<int> &arr){
    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;
}