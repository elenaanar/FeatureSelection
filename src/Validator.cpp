#include "Validator.h"

// Function to validate the classifier
double Validator::validate(vector<int> featureSubset, string dataLoc)
{ 
  Classifier classifier(featureSubset);
  classifier.train(dataLoc);

  double DataSize = classifier.getNumDataPoints();

  double correctPredictions = 0;
  std::clock_t start = std::clock();

  // Leave-One-Out
  for (int id = 0; id < DataSize; id++)
  {
    correctPredictions += evaluate(id, classifier);
  }
  std::clock_t end = std::clock();
  double timeTaken = (end - start)/(double)CLOCKS_PER_SEC;
  

  return correctPredictions / DataSize;
}

// Function to evaluate the classifier for each data point
int Validator::evaluate(int id, Classifier &classifier)
{
  // Get the true class label from the data
  int ClassLabelValue = 0;
  const auto &data = classifier.getData();
  int trueClassLabel = static_cast<int>(data[id][0]);

  int predictedClassLabel = classifier.test(id);

  if (predictedClassLabel == trueClassLabel)
  {
    ClassLabelValue = 1;
  }
  // Return 1 if the classifier is correct, 0 if the classifier is incorrect
  return ClassLabelValue; // shoutout to 120b
}