// Quick sort
// https://www.w3schools.com/dsa/dsa_algo_quicksort.php
#include<iostream>
using namespace std;
// Partition function rearranges elements based on the pivot
int partition(int a[], int lb, int ub){
    int i,j,pivot;
    pivot = a[ub];                    // Choosing the last element as pivot
    i = lb - 1;
    for(j=lb;j<ub;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);          // function call to swap array values
        }
    }
    swap(a[i + 1],a[ub]);             // Place pivot in its correct sorted position
    return i + 1;                     // Return pivot's index
}
// Quick Sort recursive function
void quicksort(int a[], int lb, int ub){
    int p;
    if(lb<ub){                       // Base condition: continue only if range has at least 2 elements
        p = partition(a,lb,ub);
        quicksort(a,lb,p-1);
        quicksort(a,p+1,ub);
    }
}
// main function - execution starts here
int main(){
    int a[20],n,i;
    cout<<"Enter the no. of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(i=0;i<n;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>a[i];
    }
    cout<<"\nUnsorted Array:\n";
    cout<<"[";
    for(i=0;i<n;i++){
        cout<<" "<<a[i];
    }
    cout<<"]\n";
    quicksort(a,0,n-1);                 //quick sort func. call - it all starts here !                
    cout<<"\nSorted Array:\n";
    cout<<"[";
    for(i=0;i<n;i++){
        cout<<" "<<a[i];
    }
    cout<<"]\n";
    return 0;
}
