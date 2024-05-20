/*
    Authors: Elena Hosseinmardi: ehoss003
            Arrdya Srivastav: asriv033
            Anthony Padilla: apadi089
            Luis Magallanes Banuelos: lmaga024
*/
#include <iostream> 
#include "src/Search.h"
#include <vector>
using namespace std;

int main(){

    Search search; 
    int numFeatures; 
    int userChoice;
    unordered_map<int, bool> subset ;

    cout << " Welcome to JAKLE's Feature Selection Algorithm\n" << endl;
    cout << "Please enter total number of features: " ;
    cin >> numFeatures;
    cout << endl; 
    cout << "Enter the number of the algorithm you'd like to run\n" << "1.Forward Selection\n" << "2.Backward Selection\n" << "3.Special Algorithm to steal data\n" << endl;
    cin >> userChoice;
    cout << "Using a random evalation, with no features, I get an accuracy of " << static_cast<double>(rand()) / RAND_MAX  << endl;
    
    switch(userChoice)
    {
    case 1:
       
        subset = search.greedyForward(numFeatures);
        cout << " Search Finished ! The best feature subset was {" ;
        for(auto it = subset.begin(); it != subset.end(); ++it){
            cout << it->first << " "; 
        }

        if(subset.size() == 0){
            cout << "No features selected." << endl;
        }
        cout << "} with an accuracy of " << search.bestAccuracy * 100 << "%";
        break;
    case 2: 
        subset = search.greedyBackward(numFeatures);
          cout << " Search Finished ! The best feature subset was {" ;
        for(auto it = subset.begin(); it != subset.end(); ++it){
            cout << it->first << " "; 
        }

        if(subset.size() == 0){
            cout << "No features selected." << endl;
        }
        cout << "} with an accuracy of " << search.bestAccuracy * 100 << "%";
        break;
    case 3:
        cout << "UHH under construction can we have data tho pls ;)\n";
        break;
    
    }
  
    // cout << endl;

    // for(auto it = subset2.begin(); it != subset2.end(); ++it){
    //     cout << it->first << " "; 
    // }

    // if(subset2.size() == 0){
    //     cout << "No features selected." << endl;
    // }
   

    return 0; 
}