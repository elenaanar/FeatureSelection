#include "Validator.h"

// Function to validate the classifier
double Validator::validate(vector<int> featureSubset, string dataLoc) {

  Classifier classifier(featureSubset);
  classifier.train(dataLoc);

  int DataSize = classifier.getNumDataPoints();

  // Initialize variables for accuracy calculation
  int correctPredictions = 0;

  // Leave-One-Out
  for (int id = 0; id < DataSize; id++) {
    // Evaluate the classifier for each data point
    correctPredictions += evaluate(id, classifier);
  }

  // Calculate and return the accuracy
  return static_cast<double>(correctPredictions) / DataSize;
}

int Validator::evaluate(int id, Classifier &classifier) {
  // Get the true class label from the data
  const auto &data = classifier.getNumDataPoints();
  int trueClassLabel = static_cast<int>(data[id][0]);

  // Test the classifier with the given ID
  int predictedClassLabel = classifier.test(id);

  // Return 1 if the classifier is correct, 0 if the classifier is incorrect
  return (predictedClassLabel == trueClassLabel) ? 1 : 0; // shoutout to 120b
}
