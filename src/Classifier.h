#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <ctime>
using namespace std;

#ifndef CLASSIFIER_H
#define CLASSIFIER_H

class Classifier
{
private:
    vector<vector<double> >
        data; // 2D vector to store data, index is the id and // the first point
              // in     the sub array is the class.
    vector<vector<double> > normalizingData;
    vector<int> featureSubset;
    // int numDataPoints;
    int numFeatures;
    double maxClass;

public:
    Classifier(vector<int> featureSubsetInput);
    void train(string dataLoc);
    int test(int id);
    int test(vector<double> &features);
    void print();
    int getNumFeatures();
    int getNumDataPoints();
    const vector<vector<double> > &getData() const;

private:
    void normalize(int col);
    void normalizeFeatures(vector<double> &features);
    int nn(vector<double> &, int excludeRow = -1);
    int nn(int);
    double distance(const vector<double> &, int id2) const;
    void writeToFile(string fileName);
};

#endif