// insertion operation on array direct - beginning
#include<iostream>
using namespace std;
int main(){
    int a[20],i,ub,lb,val;
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
    // insert value at front
    cout<<"\nEnter the value to insert: ";
    cin>>val;
    for(i=ub-1;i>=lb;i--){
        a[i+1] = a[i];
    }
    a[lb] = val;
    ub++;
    cout<<"\nNew Array:\n";
    cout<<"[";
    for(i=lb;i<ub;i++){
        cout<<" "<<a[i];
    }
    cout<<"]";
    return 0;
}