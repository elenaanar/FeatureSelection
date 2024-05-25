#include "Classifier.h"

// Constructor
Classifier::Classifier(int num) {
    numFeatures = num;
}

// Function to print a 2D vector with the index as the id
void Classifier::print(){
    // Print the table header
    cout << "---------------------------------------------------------------------------------------------" << endl;
    printf("ID\tClass\t");
    for (int i = 1; i <= numFeatures; i++) {
        printf("F_%d\t", i);
    }
    printf("\n");
    cout << "---------------------------------------------------------------------------------------------" << endl;

    // Print the table rows
    for (int i = 0; i < data.size(); i++) {
        printf("%d\t", i);
        for (int j = 0; j < data[i].size(); j++) {
            printf("%.2f\t", data[i][j]);
        }
        cout << endl;
    }
}


// Train the classifier
void Classifier::train(string dataLoc) {
    // Read in the data file
    ifstream inputFile(dataLoc);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open data file." << std::endl;
        return;
    }

    // Read data from file and store in vector
    string mystring;
    std::vector<double> featureVector;
    int count = 0;
    while (inputFile >> mystring) {
        double value = std::stod(mystring);
        featureVector.push_back(value);
        count++;
        if (count == numFeatures + 1) {
            data.push_back(featureVector);
            featureVector.clear();
            count = 0;
        }
    }
    inputFile.close();
    // print();
    //normalize the data to fit between 0 and 1 for all features
    //starting at 1 so that we dont normalize the class
    for(int i = 1; i <= numFeatures; i++){
        normalize(i);
    }

    //printing the data vector
    print();
}
// Predict the class label for a given feature vector
int Classifier::test(vector<double>& features) {
   return 0;
}

int Classifier::test(int id){
   return 0;
}

// Calculate the Euclidean distance between two data points
double Classifier::distance(vector<double>& features, int id2) {
    // Get the feature vector corresponding to the given id
    vector<double>& featureVector = data[id2];

    // Calculate the Euclidean distance between the two feature vectors
    double sum = 0.0;
    for (int i = 1; i <=numFeatures; i++) {
        double diff = features[i-(featureVector.size() - features.size())] - featureVector[i];
        sum += diff * diff;
    }
    double distance = sqrt(sum);

    return distance;
}

// Normalize the data
void Classifier::normalize(int col) {
    // Find the minimum and maximum values in the specified column
    double minVal = data[0][col];
    double maxVal = data[0][col];
    for (const auto& featureVector : data) {
        double value = featureVector[col];
        if (value < minVal) {
            minVal = value;
        }
        if (value > maxVal) {
            maxVal = value;
        }
    }
    vector<double> temp;
    temp.push_back(minVal);
    temp.push_back(maxVal);
    normalizingData.push_back(temp);
    // Normalize the values in the specified column
    for (auto& featureVector : data) {
        double value = featureVector[col];
        double normalizedValue = (value - minVal) / (maxVal - minVal);
        featureVector[col] = normalizedValue;
    }
}

// Normalize the features
void Classifier::normalizeFeatures(vector<double>& features) {
    for (int i = 0; i < numFeatures; i++) {
        double value = features[i];
        double normalizedValue = (value - normalizingData[i][0]) / (normalizingData[i][1] - normalizingData[i][0]);
        features[i] = normalizedValue;
    }
}