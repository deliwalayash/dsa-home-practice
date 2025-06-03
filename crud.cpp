#include<iostream>
#include<vector>
using namespace std;

class Sort{
    public:
    int arr;
    int size;

    void bubblesort(vector<int>& arr,int size);
    void insertionsort(vector<int>& arr,int size);
    void selectionsort(vector<int>& arr,int size);
    void printarr(vector<int>& arr,int size);
};

void Sort::bubblesort(vector<int>& arr,int size){
    for(int i = 0 ; i < arr.size() - 1;i++){
        for(int j = 0; j <arr.size()-1 ;j++){
            if(arr[j] > arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void Sort::insertionsort(vector<int>& arr,int size){
    int key,j;
    
    for(int i = 1; i < arr.size();i++){
        int key=arr[i];
        int j = i-1;
        while (j>= 0 && key < arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
            arr[j+1]=key;
         
    } 
 
   
}
void Sort::selectionsort(vector<int>& arr,int size){
    for(int i = 0; i < arr.size() ; i++){
        int minidx=i;
        for(int j = i+1;j < arr.size() ; j++){
            if(arr[j] < arr[minidx]){
                minidx=j;
            }
        }
        int temp=arr[minidx];
        arr[minidx]=arr[i];
        arr[i]=temp;
    }
}
void Sort::printarr(vector<int>& arr,int size){
    for(int val:arr){
        cout << val <<" ";
    }
    cout <<endl;
}

int main(){

  
    int size;
    cout <<"Enter size of array:";
    cin >> size;
    vector<int> arr(size);
    for(int i = 0 ; i < arr.size() ; i++ ){
        cout <<"Enter Data:";
        cin >> arr[i];
    }
    int choice;
    Sort s1;
    do
    {
        cout <<"Enter 1 for bubblesort:"<< endl;
        cout <<"Enter 2 for insertion sort:"<<endl;
        cout <<"Enter 3 for selection sort:" << endl;
        cout <<"Enter you choice:";
        cin>> choice;
        switch (choice)
        {
        case 1:
            {
                s1.bubblesort(arr,size);
                s1.printarr(arr,size);
                break;
            }
        case 2:
            {
                s1.insertionsort(arr,size);
                s1.printarr(arr,size);
                break;
            }
        case 3:
            {
                s1.selectionsort(arr,size);
                s1.printarr(arr,size);
                break;
            }
        
        default:
            break;
        }
    } while (choice !=0);
}