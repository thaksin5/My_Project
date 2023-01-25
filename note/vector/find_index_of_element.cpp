#include <iostream>
#include <vector>
#include <algorithm> // find
using namespace std;

int getIndex(vector<int> v, int data){
    auto itr = find(v.begin(), v.end(), data);
    // if exist
    if(itr != v.end()){
        int index = itr - v.begin();
        return index;
    }else{ return -1;}
}

int main(){
    vector<int> num_list = {2, 4, 6, 8, 10};
    int index = getIndex(num_list, 2);
    cout<<index<<endl;

    return 0;   
}