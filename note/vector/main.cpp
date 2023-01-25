#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> num = {2, 4, 6, 8, 10};
    num.pop_back(); // remove last element
    for(int i=0;i<num.size();i++){
        cout << num[i] << " ";
    }
    cout<<endl;

    num.erase(num.begin()); // remove first element
    for(int i=0;i<num.size();i++){
        cout << num[i] << " ";
    }
    cout<<endl;

    // remove by index
    // vec.erase(vec.begin() + index);
    vector<int> num2 = {1, 2, 3, 4, 5, 6};
    num2.erase(num2.begin()+2); // remove index(position) 2
    for(int i=0;i<num2.size();i++){
        cout << num2[i] << " ";
    }

    cout<<endl;

    // clear all
    vector<int> num3 = {2,3,4,5,6,7};
    num3.clear();
    cout<<num3.size()<<endl;

    return 0;
}