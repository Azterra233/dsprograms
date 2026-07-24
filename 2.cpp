// Template program 2
#include<iostream>
#include<string>
using namespace std;
template <typename T>
class calculator{
    T num1, num2;
    public:
        calculator(T n1, T n2){
            num1 = n1;
            num2 = n2;
        }
        T add(){
            return num1+num2;
        }
        T multiply(){
            return num1*num2;
        }
};
int main(){
    calculator<int>ob1(3,4);
    calculator<float>ob2(4.5,5.1);
    calculator<string>ob3("Hai","Ben");
    cout<<ob1.add()<<endl;
    cout<<ob2.add()<<endl;
    cout<<ob3.add()<<endl;
    return 0;
}
