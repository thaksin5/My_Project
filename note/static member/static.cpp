#include <iostream>
#include <vector>
using namespace std;

class myClass{
    public:
        // static data member
        static int count;
        static int x=2;
        vector<int> num = {1,2,3};
        static vector<int> num1;
        myClass(){
            count++;
        }
        int getCount1(){
            return count;
        }
        // static member function
        static int getCount(){
            return count;
            // return x (error because it can access only data static member)
        }
};

int myClass::count = x;
vector<int>

int main(){
    myClass c1, c2, c3;

    cout<<myClass::getCount()<<endl;

    return 0;
}