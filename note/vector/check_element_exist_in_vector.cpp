#include <iostream>
#include <vector>
#include <algorithm> // find


// we can use find
int main()
{
    std::vector<int> v = { 4, 7, 5, 2, 6, 9 };
    int key = 26;
 
    if (std::find(v.begin(), v.end(), key) != v.end()){
        std::cout << "Element found";
    }
    else {
        std::cout << "Element not found";
    }
 
    return 0;
}