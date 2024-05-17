#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#ifndef _SEARCH_H_
#define _SEARCH_H_
using namespace std;

class Search {
    public: 
    double evaluate(const vector<int>&); 
    vector<int> greedyForward(int); 
};

#endif