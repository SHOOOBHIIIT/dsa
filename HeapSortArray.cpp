#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i){
    int left=2*i+1;
    int right = 2*i+2;
    int large=i;
    if (left<n && arr[large]<arr[left] ){
        large=left;
    }
    if (arr[large]<arr[right] && right<n) large = right;

    if(i!=large){
        swap(arr[i], arr[large]);
        maxHeapify(arr, n, large );
    }
}

void buildHeap(int arr[], int n){
    for(int i=n/2-1; i>=0; i--){
        maxHeapify(arr, n, i);
    }
}

void sortMaxHeap(int arr[], int n){
    buildHeap(arr, n);
    int last=n;
    for(int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    // Your code goes here
    int arr[5]={5,7,3,8,5};

    sortMaxHeap(arr, 5);

    for (int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
} 
