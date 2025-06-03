int pivotidx=partiton(arr,low,high);
quicksort(arr,low,pivotidx - 1)
quicksort(arr,pivotidx+1,high)

void partiion(arr,low,high){
    int pivot=arr[low];

    int count = 0,temp;

    for(int i = low ; i < high ; i++){
        if(arr[i] < pivot){
            count++;
        }
    }

    int pidx=start + count;

    temp=arr[low];
    arr[low]=arr[pidx]
    arr[pidx]=temp;

    int left=low
    int right = high

    while(left < pidx && right > pidx){
        while(arr[left] < pivot){
            left++;
        }
        while(arr[right] > pivot){
            right--;
        }
        if(left < pidx && right > pidx){
            swap(arr[left],arr[right])
            left++
            right--
        }
    }
    return pidx;
}