#include "array.cpp"
#include<string>
int main(){
    array<int>obj1;
    array<std::string>obj2;
    std::cout<<"\nInteger array:"<<std::endl;            //since endl, string etc. are all defined in the standard namespace. We are not using "using namespace std;" due to ambiguity hence we explicitly put std:: everytime something in it comes.
    obj1.displayarray();
    std::cout<<"\nString array:"<<std::endl;
    obj2.displayarray();
    return 0;
}