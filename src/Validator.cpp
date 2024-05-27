#include "Validator.h"

// Function to validate the classifier
double Validator::validate(vector<int> featureSubset, string dataLoc) {
    // cout << dataLoc << endl;
  Classifier classifier(featureSubset);
  classifier.train(dataLoc);

  double DataSize = classifier.getNumDataPoints();

  // Initialize variables for accuracy calculation
  double correctPredictions = 0;

  // Leave-One-Out
  for (int id = 0; id < DataSize; id++) {
    // Evaluate the classifier for each data point
    correctPredictions += evaluate(id, classifier);
    // cout << correctPredictions << endl;
  }

  // Calculate and return the accuracy
  return correctPredictions / DataSize;
}

int Validator::evaluate(int id, Classifier &classifier) {
  // Get the true class label from the data
    int ClassLabelValue = 0; 
  const auto &data = classifier.getData();
  int trueClassLabel = static_cast<int>(data[id][0]);
    // cout << trueClassLabel << endl;

  // Test the classifier with the given ID
  int predictedClassLabel = classifier.test(id);


    // cout << predictedClassLabel << endl;
    if (predictedClassLabel == trueClassLabel){
        ClassLabelValue = 1;
    }
  // Return 1 if the classifier is correct, 0 if the classifier is incorrect
  return ClassLabelValue; // shoutout to 120b
}
