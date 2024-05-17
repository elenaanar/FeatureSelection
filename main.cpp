#include <iostream> 
#include "src/Search.h"
#include <vector>
using namespace std;

int main(){

    int features = 10; 
    Search search; 
    vector<int> vec;
    vec = search.greedyForward(features);

    // for (unsigned i = 0; i < vec.size(); ++i){
    //     cout << vec[i] << " "; 
    // }
    return 0; 
}