#include <iostream>
#include <string>
using namespace std;

/*
string add(string s1, string s2){
    return s1 + s2;
}

int add(int n1, int n2){
    return n1 + n2;
}
*/
// we can see that we create samefunction but different data type
// to fix this we use template

template <class T>
T add(T x1, T x2){
    return x1 + x2;
}

int main(){
    // add<vector>(num1, num2) 
    cout<<add<int>(1, 2)<<endl;
    cout<<add<string>("Thaksin", "Chang")<<endl; // it gonna be array character string
    cout<<add<double>(1.1, 2.1)<<endl;

    return 0;
}