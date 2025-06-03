#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector<int> &arr,int low,int high);
int partition(vector<int> &arr,int low,int high);

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

    quicksort(arr,0,size-1);


    cout <<"\n-------after---------\n";

    for(int i = 0 ; i < size ; i ++){
        cout << arr[i] <<" ";
    }

    return 0;

}
void quicksort(vector<int> &arr,int low,int high){
    if(low >=high)
    return;

    int pivotidx=partition(arr,low,high);
    quicksort(arr,low,pivotidx-1);
    quicksort(arr,pivotidx+1,high);


}
int partition(vector<int> &arr,int low,int high){

    int pivot = arr[low];
    int count=0,temp;

    for(int i = low ; i <= high ; i++){
        if(arr[i] <pivot){
        count++;
        }
    }
    int pIdx=low + count;

    temp=arr[low];
    arr[low]=arr[pIdx];
    arr[pIdx]=temp;
    int left = low;

    int right = high;
    while (left < pIdx && right > pIdx)
    {
        while (arr[left] < pivot)
        {
            left++;
        }
        while(arr[right] > pivot){
            right--;
        }
        if(left < pIdx && right > pIdx){
            temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
        }
        
    }
    return pIdx;
    
}
