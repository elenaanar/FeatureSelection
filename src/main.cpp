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
using namespace std;

// int main() {

//   Search search;
//   int numFeatures;
//   int userChoice;
//   unordered_map<int, bool> subset;

//   cout << " Welcome to JAKLE's Feature Selection Algorithm\n" << endl;
//   cout << "Please enter total number of features: ";
//   cin >> numFeatures;
//   cout << endl;
//   cout << "Enter the number of the algorithm you'd like to run\n"
//        << "1.Forward Selection\n"
//        << "2.Backward Selection\n"
//        << "3.Special Algorithm to steal data\n " << endl;
//           cin >>
//       userChoice;
//   cout << "Using a random evalation, with no features, I get an accuracy of "
//   << static_cast<double>(rand()) / RAND_MAX  << endl;

//               switch(userChoice)
//               {
//               case 1:

//                   subset = search.greedyForward(numFeatures);
//                   cout << " Search Finished ! The best feature subset was {"
//                   ; for(auto it = subset.begin(); it != subset.end(); ++it){
//                       cout << it->first << " ";
//                   }

//                   if(subset.size() == 0){
//                       cout << "No features selected." << endl;
//                   }
//                   cout << "} with an accuracy of " << search.bestAccuracy *
//                   100 <<"%";
//           break;
//       case 2:
//           subset = search.greedyBackward(numFeatures);
//             cout << " Search Finished ! The best feature subset was {" ;
//           for(auto it = subset.begin(); it != subset.end(); ++it){
//               cout << it->first << " ";
//           }

//           if(subset.size() == 0){
//               cout << "No features selected." << endl;
//           }
//   cout << "} with an accuracy of " << search.bestAccuracy * 100 << "%";
//   break;
// case 3:
//   cout << "UHH under construction can we have data tho pls ;)\n";
//   break;
// }

// cout << endl;

// for(auto it = subset2.begin(); it != subset2.end(); ++it){
//     cout << it->first << " ";
// }

// if(subset2.size() == 0){
//     cout << "No features selected." << endl;
// }

// return 0;
// }

int main()
{
    vector<int> featureSubset;
    // featureSubset.push_back(1);
    // featureSubset.push_back(2);
    featureSubset.push_back(1);
    // featureSubset.push_back(4);
    featureSubset.push_back(15);
    // featureSubset.push_back(6);
    featureSubset.push_back(27);
    // featureSubset.push_back(8);
    // featureSubset.push_back(9);
    // featureSubset.push_back(10);
    Classifier classifier(featureSubset); // change num features depending on
                                          // the dataset classifier.train("data/small-test-dataset.txt");
                                          // cout << classifier.test(0) << endl;
    Validator validator;
    cout << validator.validate(featureSubset, "data/large-test-dataset.txt");
    // vector<double> features;
    // //{5.07, 3.14, 1.29, 0.58, 2.73, 1.91, 4.60, 3.36, 4.03, 2.85}
    // // datapoint 0 copied from the dataset
    // features.push_back(5.07);
    // features.push_back(3.14);
    // features.push_back(1.29);
    // features.push_back(0.58);
    // features.push_back(2.73);
    // features.push_back(1.91);
    // features.push_back(4.60);
    // features.push_back(3.36);
    // features.push_back(4.03);
    // features.push_back(2.85);
    // cout << classifier.test(features) << endl;

    return 0;
}
