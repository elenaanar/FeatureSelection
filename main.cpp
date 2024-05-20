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

    int features = 5; 
    Search search; 
    // unordered_map<int, bool> subset = search.greedyBackward(features);
    unordered_map<int, bool> subset2 = search.greedyForward(features);

    return 0; 
}