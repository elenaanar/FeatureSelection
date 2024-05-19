/*
    Authors: Elena Hosseinmardi: ehoss003
            Arrdya Srivastav: asriv033
            Anthony Padilla: apadi089
            Luis Magallanes Banuelos: lmaga024
*/
#include <iostream> 
#include "src/Search.h"
#include <vector>
using namespace std;

int main(){

    int features = 10; 
    Search search; 
    unordered_map<int, bool> subset = search.greedyBackward(features);
    unordered_map<int, bool> subset2 = search.greedyForward(features);

    // for(auto it = subset.begin(); it != subset.end(); ++it){
    //     cout << it->first << " "; 
    // }

    // if(subset.size() == 0){
    //     cout << "No features selected." << endl;
    // }

    // cout << endl;

    // for(auto it = subset2.begin(); it != subset2.end(); ++it){
    //     cout << it->first << " "; 
    // }

    // if(subset2.size() == 0){
    //     cout << "No features selected." << endl;
    // }

    return 0; 
}