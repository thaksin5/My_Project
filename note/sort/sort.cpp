#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort_number(std::vector<int> &_num_list){
    std::sort(_num_list.begin(), _num_list.end(), [](int num1, int num2){
        return num1 < num2;
    });
}

int main(){
    std::vector<int> num_list = {4,10,2,5,8};
    sort_number(num_list);
    for(auto& i:num_list){
        cout<<i<<endl;
    }

    return 0;
}