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
        vector<int> featureSubset;
        int numDataPoints;
        int numFeatures;
    public:
        Classifier(vector<int> featureSubsetInput);
        void train(string dataLoc);
        int test(int id);
        int test(vector<double>& features);
    private: 
        void normalize(int col);
        void normalizeFeatures(vector<double>& features);
        void print();
        int getNumFeatures();
        int getNumDataPoints();
        int nn(vector<double> &);
        double distance(const vector<double>&, int id2) const;
};

#endif