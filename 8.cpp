// insertion at postion logic
#include<iostream>
using namespace std;
int main(){
    int a[20],i,lb,ub,pos,val;
    cout<<"Enter the lower and upper bounds of array: ";
    cin>>lb>>ub;
    cout<<"Enter elements:\n";
    for(i=lb;i<ub;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>a[i];
    }
    cout<<"Array:\n";
    cout<<"[";
    for(i=lb;i<ub;i++){
        cout<<" "<<a[i];
    }
    cout<<"]\n";
    cout<<"\nEnter value to insert: ";
    cin>>val;
    cout<<"Enter position(index): ";
    cin>>pos;
    for(i=ub-1;i>=pos;i--){
        a[i+1] = a[i]; 
    }
    a[pos] = val;
    ub++;
    cout<<"\nNew Array:\n";
    cout<<"[";
    for(i=lb;i<ub;i++){
        cout<<" "<<a[i];
    }
    cout<<"]";
    return 0;
}