// array
// insertion sort
#include<iostream>
using namespace std;
int main(){
    int a[20],n,i,j,key;
    cout<<"Enter the no. of array elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(i=0;i<n;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>a[i];
    }
    cout<<"Unsorted Array:\n";
    cout<<"[";
    for(i=0;i<n;i++){
        cout<<" "<<a[i];
    }
    cout<<"]";
    for(i=1;i<n;i++){
        key = a[i];
        j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
    cout<<"\nSorted Array:\n";
    cout<<"[";
    for(i=0;i<n;i++){
        cout<<" "<<a[i];
    }
    cout<<"]";
    return 0;
}