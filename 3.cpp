// Array operations using Template 
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class array_op{
    T a[100];
    int n,i;
    T s;
    public:
        void readdata();
        T findarraysum(T a);
        void display();
};
template<typename T> void array_op<T>::readdata(){
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements:\n";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
}
template<typename T> void array_op<T>::display(){
    cout<<"The elements:\n";
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
} 
template<typename T> T array_op<T>::findarraysum(T key){
    s = a[0];
    for(i=0;i<n;i++){
        s += a[i];
    }
    s+=key;
    return s;
}
int main(){
    array_op<int> ob1;
    ob1.readdata();
    ob1.display();
    cout<<"\nArray Sum with key = "<<ob1.findarraysum(7)<<endl;
    cout<<"Array sum without key = "<<ob1.findarraysum(0)<<endl;
    array_op<string> ob2;
    ob2.readdata();
    ob2.display();
    return 0;
}
