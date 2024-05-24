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

    //normalize the data to fit between 0 and 1 for all features
    //starting at 1 so that we dont normalize the class
    for(int i = 1; i <= numFeatures; i++){
        normalize(i);
    }

    //printing the data vector
    print();
}
// Predict the class label for a given feature vector
int Classifier::test(const std::vector<double>& features) {
    // TODO: Implement predict function
    return 0; // Placeholder return value
}

int Classifier::test(int id){
    // TODO: Implement predict function
    return 0; // Placeholder return value
}

// Calculate the Euclidean distance between two data points
double Classifier::distance(int id1, int id2) {
    return 0.0;
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
    
    // Normalize the values in the specified column
    for (auto& featureVector : data) {
        double value = featureVector[col];
        double normalizedValue = (value - minVal) / (maxVal - minVal);
        featureVector[col] = normalizedValue;
    }
}