// Merge sort
// Ref: https://www.w3schools.com/dsa/dsa_algo_mergesort.php
// divide n conquer dekho MIT divide n conquer fft
#include<iostream>
using namespace std;

void merge(int a[], int lb, int mid, int ub){
    int temp[20],i,j,k;
    i = lb; j = mid + 1; k = lb;
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            i++;
        }else{
            temp[k]=a[j];
            j++;
        }
        k++;
    }if(i>mid){
        // Copy remaining elements from right subarray
        while(j<=ub){
            temp[k]=a[j];
            j++; k++; 
        }
    }else{
        // Copy remaining elements from left subarray
        while(i<=mid){
            temp[k]=a[i];
            i++; k++;
        }
    }
    // Copy sorted temporary array back to original array
    for(i=lb;i<=ub;i++){
        a[i]=temp[i];
    }
}

void mergesort(int a[], int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;       // Prevents potential integer overflow
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}


int main(){
    int a[20],i,lb,ub;
    cout<<"Enter the lower and upper bounds of array: ";
    cin>>lb>>ub;
    cout<<"Enter elements:\n";
    for(i=lb;i<ub;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>a[i];
    }
    cout<<"\nUnsorted Array:\n";
    cout<<"[";
    for(i=lb;i<ub;i++){
        cout<<" "<<a[i];
    }
    cout<<"]\n";
    mergesort(a,lb,ub);
    cout<<"\nSorted Array:\n";
    cout<<"[";
    for(i=lb;i<ub;i++){
        cout<<" "<<a[i];
    }
    cout<<"]\n";
    return 0;
}
    