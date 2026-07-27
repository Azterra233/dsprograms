//insertion operation on array direct - end
#include<iostream>
using namespace std;
int main(){
    int a[20],i,lb,ub,val;
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
    // insertion at end logic
    cout<<"\nEnter value to insert: ";
    cin>>val;
    a[ub] = val;
    ub++;
    cout<<"\nNew Array:\n";
    cout<<"[";
    for(i=lb;i<ub;i++){
        cout<<" "<<a[i];
    }
    cout<<"]";
    return 0;
}