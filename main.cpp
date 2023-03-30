#include <iostream>
#include <vector>
#include <stack>
using namespace std;



void swap(int* num1,int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partitionArr(int arr[],int start,int ends){
    int pivotElement = arr[ends];
    int i = start-1;

    for(int j=start;j<ends;j++){
        if(arr[j]<pivotElement){
            i++;
            /*int temp =arr[j];
            arr[j] = arr[i];
            arr[i] = temp;*/
            swap(&arr[i],&arr[j]);
        }
    }
    /*arr[ends] = arr[i+1];
    arr[i+1] = pivotElement;*/
    swap(&arr[ends],&arr[i+1]);

    return i+1;
}


void quickSort(int arr[],int start,int ends){
    if(start<ends){
        int pivotIndex = partitionArr(arr,start,ends);
        quickSort(arr,start,pivotIndex-1);
        quickSort(arr,pivotIndex+1,ends);
    }

}

void quicksort_iterative(int arr[], int low, int high) {
    stack<pair<int, int>> stk;
    stk.push(make_pair(low, high));
    while (!stk.empty()) {
        int start = stk.top().first;
        int end = stk.top().second;
        stk.pop();
        int p = partitionArr(arr, start, end);
        if (p-1 > start) {
            stk.push(make_pair(start, p-1));
        }
        if (p+1 < end) {
            stk.push(make_pair(p+1, end));
        }
    }
}




int main()
{
    int arr[]  = {10,20,59,11,73,35,20,56,7989,259,792,200};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort_iterative(arr,0,n-1);
    for(int x:arr){
        cout<<x<<"  ";
    }
    return 0;
}
