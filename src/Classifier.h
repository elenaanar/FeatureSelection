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
        vector<vector<double> > normalizingData;
        int numFeatures;
    public:
        Classifier(int numFeatures);
        double distance(vector<double>&, int id2);
        void train(string dataLoc);
        int test(int id);
        int test(vector<double>& features);
        void normalize(int col);
        void normalizeFeatures(vector<double>& features);
        void print();
};

#endif