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
    // Print the feature vector
    cout << "Feature vector: ";
    for (int i = 0; i < features.size(); i++) {
        cout << features[i] << " ";
    }
    // Normalize the features
    normalizeFeatures(features);

    // Print the normalized feature vector
    cout << "\nNormalized feature vector: ";
    for (int i = 0; i < features.size(); i++) {
        cout << features[i] << " ";
    }
    // Calculate the distances between the given features and all data points
    // Find the index of the closest neighbor
    std::vector<double> distances;
    double minDistance = INT_MAX;
    int closestNeighborIndex = 0;
    for (int i = 0; i < data.size(); i++) {
        double dist = distance(features, i);
        distances.push_back(dist);
        if (distances[i] < minDistance) {
            minDistance = distances[i];
            closestNeighborIndex = i;
        }
    }
    
    // Return the class label of the closest neighbor
    cout << "Closest neighbor: " << closestNeighborIndex << endl;
    return data[closestNeighborIndex][0];
}

int Classifier::test(int id){
    // Calculate the distances between the given features and all data points
    // Find the index of the closest neighbor
    std::vector<double> distances;
    double minDistance = INT_MAX;
    int closestNeighborIndex = 0;
    for (int i = 0; i < data.size(); i++) {
        if(id != i){
            double dist = distance(data[id], i);
            cout << i << " " << dist << endl;
            distances.push_back(dist);
            if (distances[distances.size() - 1] < minDistance) {
                minDistance = distances[distances.size() - 1];
                closestNeighborIndex = i;
            }
        }
    }
    cout << closestNeighborIndex << endl;
    // Return the class label of the closest neighbor
    return data[closestNeighborIndex][0];
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