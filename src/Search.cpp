#include "Search.h"

double Search::evaluate(const vector<int>& subset){
    srand(static_cast<unsigned int>(time(0)));
    return static_cast<double>(rand()) / RAND_MAX;
}



vector<int> Search::greedyForward(int totalFeatures){
    vector<int> currSubset; 
    vector<int> bestSubset; 
    double bestAcc = 0.0; 
    
    for (unsigned i = 0; i < totalFeatures; ++i){ 
        double currBestAcc = 0.0; 
        int bestFeature = -1; 
        for (unsigned j = 0; j < totalFeatures; ++j){
            //if the feature is not already in the current subset: 
            if (find(currSubset.begin(), currSubset.end(), j) == currSubset.end()){
                vector<int> tempset = currSubset; 
                tempset.push_back(j); //explore next feature 

                double a = evaluate(tempset); 
                if (a > currBestAcc){ //if feature yields more accuracy than last, set as best feat
                    currBestAcc = a; 
                    bestFeature = j; 
                }
            }
        }
        if (bestFeature != -1){ //if we found a best feature to add
            currSubset.push_back(bestFeature);
            if(currBestAcc > bestAcc){ //check if this is an overall better subset
                bestAcc = currBestAcc; 
                bestSubset = currSubset; 
            }
        }
    }

    return bestSubset; 
}