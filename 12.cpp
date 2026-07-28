// linear search
#include<iostream>
using namespace std;
int main(){
    int a[20],n,i,val,found;
    cout<<"Enter the no. of array elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(i=0;i<n;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>a[i];
    }
    cout<<"Array:\n";
    cout<<"[";
    for(i=0;i<n;i++){
        cout<<" "<<a[i];
    }
    cout<<"]\n";
    // search logic
    cout<<"Enter value to search: ";
    cin>>val;
    found = 0;
    for(i=0;i<n;i++){
        if(val==a[i]){
            cout<<"Element found at index: "<<i<<"\n";
            found = 1;
            break;
        }
    }
    if(!found){
        cout<<"Element not found!\n";
    }
    return 0;
}