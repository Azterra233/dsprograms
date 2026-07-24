// Bubble sort and sum of array elements
#include<iostream>
using namespace std;
int main(){
    int a[10],i,n,j,temp,sum=0;
    cout<<"Enter the no. of array elements: ";
    cin>>n;
    cout<<"Enter the array elements:\n";
    for(i=0;i<n;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>a[i];
        sum+=a[i];
    }
    cout<<"Unsorted Array:\n";
    cout<<"[";
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"]"<<"\n";
    //bubble sort logic
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout<<"Sorted Array:\n";
    cout<<"[";
    for(i=0;i<n;i++){
            cout<<a[i]<<" ";
    }
    cout<<"]"<<"\n";
    cout<<"Sum of array elements = "<<sum;
    return 0;
}