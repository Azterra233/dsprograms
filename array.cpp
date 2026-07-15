#include "array.h"
template <class T>
array<T>::array(){
    int i;
    std::cout<<"Enter the lower bound of array: ";       //no using namespace std; to prevent 'array' ambiguos error
    std::cin>>lb;
    std::cout<<"Enter the upper bound of array: ";
    std::cin>>ub;
    std::cout<<"Enter the array elements:\n";
    for(i=lb;i<=ub;i++){
        std::cin>>a[i];
    }
}
template <class T>
void array<T>::displayarray(){
    int i;
    for(i=lb;i<=ub;i++){
        std::cout<<a[i]<<" ";
    }
}


