#include <iostream>
#include <vector>
#include "Classifier.h"

using namespace std;

#ifndef VALIDATOR_H
#define VALIDATOR_H

class Validator
{
private:
public:
    double validate(vector<int>, string);
    int evaluate(int, Classifier &);
};

#endif