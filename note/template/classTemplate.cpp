#include <iostream>
#include <string>
using namespace std;

template <class T>
class Number{
    private:
        T _num;
    public:
        Number(T num):_num(num){}
        T getNum(){
            return _num;
        }
};

int main(){
    Number<int> n1(1); // integer
    cout<<n1.getNum()<<endl;

    Number<double> n2(1.5); // double
    cout<<n2.getNum()<<endl;

    Number<string> n3("Thaksin"); // string
    cout<<n3.getNum()<<endl;

    return 0;
}