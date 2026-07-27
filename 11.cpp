// deletion operation at position - direct
#include<iostream>
using namespace std;
int main(){
    int a[20],i,lb,ub,pos;
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
    cout<<"Enter position(index): ";
    cin>>pos;
    // deletion at position logic
    for(i=pos;i<=ub-1;i++){
        a[i] = a[i+1];
    }
    ub--;
    cout<<"\nNew Array:\n";
    cout<<"[";
    for(i=lb;i<ub;i++){
        cout<<" "<<a[i];
    }
    cout<<"]\n";
    return 0;
}