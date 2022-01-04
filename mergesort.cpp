#include <iostream>
using namespace std;

void enter(int arr[], int size);
void mergesort(int arr[],int low, int high);
void merge(int arr[], int low , int mid, int high);
void print(int arr[], int size);

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the values in the array : \n";
    enter(arr,size);
    mergesort(arr,0,size-1);
    print(arr,size);

    return 0;
}
void enter(int arr[], int size){
    for(int i=0; i < size ; i++){
        cin >> arr[i];
    }
}

void mergesort(int arr[],int low, int high){
    int mid;
    if(low == high){
        return;
    }
    else{
        
        mid=(low + high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void merge(int arr[], int low , int mid, int high){
    int i=low;
    int j=(mid + 1);
    int m=0;
    int size = high - low + 1;
    int *newarr = new int[size];
    
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            newarr[m]=arr[i];
            ++i;
            ++m;
        }
        else{
            newarr[m]=arr[j];
            ++j;
            ++m;
        }
        
    }
    
    while(i <= mid){
        newarr[m]=arr[i];
        ++m;
        ++i;
    }
    
    while(j <= high){
        newarr[m]=arr[j];
        ++m;
        ++j;
    }
    
    for(int c=0,b=low; c < size; c++,b++){
        arr[b]=newarr[c];
    }
    
    delete []newarr;
    newarr=nullptr;
}

void print(int arr[], int size){
    for(int i=0; i < size; i++){
        cout << arr[i] << " ";
    }
}
