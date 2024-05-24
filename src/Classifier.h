#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#ifndef CLASSIFIER_H
#define CLASSIFIER_H

class Classifier {
    private:
        vector<vector<double> > data; //2D vector to store data, index is the id and the first point in the sub array is the class.
        int numFeatures;
    public:
        Classifier(int numFeatures);
        double distance(int id1, int id2);
        void train(string dataLoc);
        int test(int id);
        int test(const vector<double>& features);
        void normalize(int col);
        void print();
};

#endif