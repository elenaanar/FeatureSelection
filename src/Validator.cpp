#include "Validator.h"

// Function to validate the classifier
double Validator::validate(vector<int> featureSubset, string dataLoc)
{ cout << "Beginning Validation\n" ;
  // cout << dataLoc << endl;
  Classifier classifier(featureSubset);
  classifier.train(dataLoc);

  double DataSize = classifier.getNumDataPoints();

  // Initialize variables for accuracy calculation
  double correctPredictions = 0;
  std::clock_t start = std::clock();
  // Leave-One-Out
  for (int id = 0; id < DataSize; id++)
  {
    // Evaluate the classifier for each data point
    correctPredictions += evaluate(id, classifier);
    // cout << correctPredictions << endl;
  }
  std::clock_t end = std::clock();
  double timeTaken = (end - start)/(double)CLOCKS_PER_SEC;
  cout << "Validation Finished. Time taken: " << timeTaken << "'s\n";
  // Calculate and return the accuracy
  return correctPredictions / DataSize;
}

int Validator::evaluate(int id, Classifier &classifier)
{
  // Get the true class label from the data
  int ClassLabelValue = 0;
  const auto &data = classifier.getData();
  int trueClassLabel = static_cast<int>(data[id][0]);
  // cout << trueClassLabel << endl;

  // Test the classifier with the given ID
  int predictedClassLabel = classifier.test(id);

  // cout << predictedClassLabel << endl;
  if (predictedClassLabel == trueClassLabel)
  {
    ClassLabelValue = 1;
  }
  // Return 1 if the classifier is correct, 0 if the classifier is incorrect
  return ClassLabelValue; // shoutout to 120b
}