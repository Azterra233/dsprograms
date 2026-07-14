#include "array.cpp"
#include<string>
int main(){
    array<int>obj1;
    array<std::string>obj2;
    std::cout<<"\nInteger array:"<<std::endl;
    obj1.displayarray();
    std::cout<<"\nString array:"<<std::endl;
    obj2.displayarray();
    return 0;
}