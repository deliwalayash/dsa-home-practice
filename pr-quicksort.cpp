#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector <int> &,int,int);
int partition(vector<int> &arr,int start,int end);

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
void quicksort(vector <int> &arr,int start,int end){
    if(start >= end)
    return;

    int pivodIdx=partition(arr,start,end);
    quicksort(arr,start,pivodIdx - 1);
    quicksort(arr,pivodIdx + 1,end);

}

    int partition(vector <int>&arr,int start,int end){

        int count=0;
        int temp;
        int pivot=arr[start];
        for(int i =start ; i <=end;i++){
            if (arr[i] < pivot){
                count++;
            }
        }

        int Pidx=start + count;

        temp=arr[start];
        arr[start]=arr[Pidx];
        arr[Pidx]=temp;

        int left=start;
        int right = end;

        while (left < Pidx && right > Pidx)
        {
            while (arr[left] < pivot)
            {
                left++;
            }
            while (arr[right] > pivot)
            {
                right--;
            }
            if(left < Pidx && right > Pidx){
                swap(arr[left],arr[right]);
                left++;
                right--;
            }   
        }
        return Pidx;
    }
