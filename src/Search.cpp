#include "Search.h"

//calls the validate feature function from the validator class
double Search::evaluate(const unordered_map<int, bool> &subset, string dataLoc)
{
  vector<int> featureSubset;
  for (const auto &[feature, value] : subset)
  {
    featureSubset.push_back(feature + 1);
  }
  Validator validator;
  return validator.validate(featureSubset, dataLoc);
}


//prints the features and accuracy
void printFeatures(const unordered_map<int, bool> &subset, double accuracy)
{
  cout << "Using features {";
  auto it = subset.begin();
  for (size_t i = 0; it != subset.end(); ++it, ++i)
  {
    if (i < subset.size() - 1)
    {
      cout << it->first + 1 << " ";
    }
    else
    {
      cout << it->first + 1;
    }
  }
  cout << "} accuracy is: " << accuracy * 100 << "%" << endl;
}


//greedy backward search
unordered_map<int, bool> Search::greedyBackward(int totalFeatures, string dataLoc)
{
  cout << "--------------------------" << endl; // added for clarity
  cout << "Greedy Backward Search:" << endl;
  cout << "--------------------------" << endl; // added for clarity

  srand(time(NULL));
  unordered_map<int, bool> currSubset;
  for (unsigned i = 0; i < totalFeatures; ++i)
  {
    currSubset[i] = true;
  }

  
  unordered_map<int, bool> globalBestSubset = currSubset;
  double globalBestAcc = evaluate(currSubset, dataLoc);
  printFeatures(currSubset, globalBestAcc);
  cout << endl;

  for (unsigned i = 0; i < totalFeatures; ++i)
  {
    double currBestAcc = 0.0;
    int worstFeature = -1;
    for (const auto &[feature, value] : currSubset)
    {
      unordered_map<int, bool> tempset = currSubset;
      tempset.erase(feature); // explore next feature
      double a = evaluate(tempset, dataLoc);
      printFeatures(tempset, a);
      if (a > currBestAcc)
      { // if feature yields less accuracy than last, set as worst feat
        currBestAcc = a;
        worstFeature = feature;
      }
    }
    if (worstFeature != -1)
    { // if we found a worst feature to delete
      currSubset.erase(worstFeature);
      if (currBestAcc >= globalBestAcc)
      { // check if this is an overall better subset
        globalBestAcc = currBestAcc;
        globalBestSubset = currSubset;
        bestAccuracy = globalBestAcc;
      }
      cout << endl
           << "Best subset this round: ";
      printFeatures(currSubset, currBestAcc);
      cout << endl;
    }
  }

  // printFeatures(globalBestSubset, globalBestAcc);
  return globalBestSubset;
}

unordered_map<int, bool> Search::greedyForward(int totalFeatures, string dataLoc)
{
  srand(time(NULL));
  cout << "--------------------------" << endl; // added for clarity
  cout << "Greedy Forward Search:" << endl;
  cout << "--------------------------" << endl; // added for clarity
  unordered_map<int, bool> currSubset;
  unordered_map<int, bool> bestSubset;
  double bestAcc = evaluate(currSubset, dataLoc);
  printFeatures(currSubset, bestAcc);
  cout << endl;
  for (unsigned i = 0; i < totalFeatures; ++i)
  {
    double currBestAcc = 0.0;
    int bestFeature = -1;
    for (unsigned j = 0; j < totalFeatures; ++j)
    {
      // if the feature is not already in the current subset:
      if (currSubset.find(j) == currSubset.end())
      {
        unordered_map<int, bool> tempset = currSubset;
        tempset[j] = true; // explore next feature

        double a = evaluate(tempset, dataLoc);
        printFeatures(tempset, a);
        if (a > currBestAcc)
        { // if feature yields more accuracy than last, set as best feat
          currBestAcc = a;
          bestFeature = j;
        }
      }
    }
    if (bestFeature != -1)
    { // if we found a best feature to add
      currSubset[bestFeature] = true;
      if (currBestAcc > bestAcc)
      { // check if this is an overall better subset
        bestAcc = currBestAcc;
        bestSubset = currSubset;
        bestAccuracy = bestAcc;
      }
      cout << endl
           << "Best subset: ";
      printFeatures(currSubset, currBestAcc);
      cout << endl;
      
    }
  }

  return bestSubset;
}