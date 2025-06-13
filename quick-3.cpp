#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector<int> &arr,int low,int high);
int partition(vector<int> &arr,int low,int high);

int main()
    
    {

    int size;
    cout <<"Enter size of Array:";
    cin >> size;
    vector<int>arr(size);

    for(int i = 0; i < size;i++){
        cout <<"Enter data:";
        cin >> arr[i];
    }
    cout <<"\n------unsorted array-----\n";
    for(int val:arr){
        cout << val <<" ";
    }
    cout << endl;

    cout <<"\n------sorted array-----\n";
    quicksort(arr,0,size-1);

    for(int val:arr){
        cout << val <<" ";
    }

    return 0;
    }

    void quicksort(vector<int> &arr,int low,int high){
        if( low >= high){
            return;
        }

        int pvtidx=partition(arr,low,high);
        quicksort(arr,low,pvtidx - 1);
        quicksort(arr,pvtidx + 1,high);
    }
    int partition(vector<int> &arr,int low,int high){

        int pivot=arr[low];
        int count=0;
        int temp;

        for(int i = low;i <= high ; i++){
            if(arr[i] < pivot){
                count++;
            }
        }

        int Pidx=low + count;
        swap(arr[low],arr[Pidx]);

        int left=low;
        int right=high;
        while(left <  Pidx && right > Pidx){
            while(arr[left] < arr[Pidx]){
                left++;
            }
            while(arr[right] > arr[Pidx]){
                right--;
            }
                swap(arr[left],arr[right]);
                left++;
                right--;
        }

        return Pidx;
    }