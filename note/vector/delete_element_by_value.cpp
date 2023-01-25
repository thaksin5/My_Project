#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vec = {2,4,6,8,10,10,10};
    vec.push_back(30);
    for(int i=0; i<vec.size(); i++){ cout<<vec[i]<<" ";}
    cout<<endl;
    vec.erase(std::remove(vec.begin(), vec.end(), 10), vec.end()); // erase by value
    for(int i=0; i<vec.size(); i++){ cout<<vec[i]<<" ";}
    
    return 0;
}
