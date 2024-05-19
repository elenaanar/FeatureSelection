#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unordered_map>

#ifndef _SEARCH_H_
#define _SEARCH_H_
using namespace std;

struct Node{
    string name;
    vector<int> subset; 
    double acc; 
};

class Search {
    public: 
    double evaluate(const unordered_map<int, bool>&);
    unordered_map<int, bool> greedyForward(int); 
    unordered_map<int, bool> greedyBackward(int);
};

#endif