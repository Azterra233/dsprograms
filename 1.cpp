// Template program 1
#include<iostream>
using namespace std;
template <typename T>                         //template created with a datatype T
T large(T n1, T n2){                          //parameterised
    return (n1>n2)?n1:n2;                     //ternary operator
}
int main(){
    cout<<large<int>(3,4)<<endl;              //object created with datatype int and large func. called
    cout<<large<float>(4.5,3.2)<<endl;        // "" float ""
    cout<<large<string>("Hai","Ciao")<<endl;  //object created with datatype string and ascii values of first letter compared, H is bigger so Hai returns
    return 0;                                    
}
