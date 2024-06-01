/*
    Authors: Elena Hosseinmardi: ehoss003
            Arrdya Srivastav: asriv033
            Anthony Padilla: apadi089
            Luis Magallanes Banuelos: lmaga024
// */
#include "src/Classifier.h"
#include "src/Search.h"
#include "src/Validator.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{

    Search search;
    string dataLoc = argv[1];
    int numFeatures = 0;
    int userChoice = stoi(argv[2]);
    unordered_map<int, bool> subset;

    cout << " Welcome to JAKLE's Feature Selection Algorithm\n"  << endl;
    cout << "Using a random evalation, with no features, I get an accuracy of " << static_cast<double>(rand()) / RAND_MAX << endl;


    // go through file and get the number of features
    ifstream inputFile(dataLoc);
    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open data file." << std::endl;
        return 1;
    }
    string mystring;
    getline(inputFile, mystring);
    istringstream ss(mystring);
    double value;
    while (ss >> value)
    {
        numFeatures++;
    }
    numFeatures-=1;


    cout << "Number of features: " << numFeatures << endl;
    inputFile.close();
    

    switch (userChoice)
    {
    case 1:

        subset = search.greedyForward(numFeatures, dataLoc);
        cout << " Search Finished ! The best feature subset was {";
        for (auto it = subset.begin(); it != subset.end(); ++it)
        {
            cout << it->first << " ";
        }

        if (subset.size() == 0)
        {
            cout << "No features selected." << endl;
        }
        cout << "} with an accuracy of " << search.bestAccuracy * 100 << "%";
        break;
    case 2:
        subset = search.greedyBackward(numFeatures, dataLoc);
        cout << " Search Finished ! The best feature subset was {";
        for (auto it = subset.begin(); it != subset.end(); ++it)
        {
            cout << it->first << " ";
        }

        if (subset.size() == 0)
        {
            cout << "No features selected." << endl;
        }
        cout << "} with an accuracy of " << search.bestAccuracy * 100 << "%";
        break;
    case 3:
        cout << "UHH under construction can we have data tho pls ;)\n";
        break;
    }

    cout << endl;

    return 0;
}

// int main(){
//     Validator validator;
//     vector<int> featureSubset;
//     string dataLoc = "data/large14.txt";
//     featureSubset.push_back(13);
//     featureSubset.push_back(32);
//     cout << validator.validate(featureSubset, dataLoc);

// }