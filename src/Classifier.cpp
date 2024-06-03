#include "Classifier.h"
#include <cmath>

using namespace std;

// Constructor
Classifier::Classifier(vector<int> featureSubsetInput)
{
    featureSubset = featureSubsetInput;
}

// take a vector and output that to a text file with spaces between each element and each row on a new line
void Classifier::writeToFile(string filename)
{
    ofstream file;
    file.open(filename);
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            file << data[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}

// Train the classifier
void Classifier::train(string dataLoc)
{
    // Read in the data file
    ifstream inputFile(dataLoc);
    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open data file." << std::endl;
        return;
    }

    // Read data from file and store in vector
    string mystring;
    std::vector<double> featureVector;
    std::clock_t start  = std::clock();

    while (getline(inputFile, mystring))
    {
        istringstream ss(mystring);
        double value;
        while (ss >> value)
        {
            featureVector.push_back(value);
        }
        data.push_back(featureVector);
        featureVector.clear();
    }
    // Get the number of features
    numFeatures = data[0].size() - 1;
    inputFile.close();
    //Count membership of each class and return the most popular class
    vector<int> classCount(2, 0);
    for (int i = 0; i < data.size(); i++)
    {
        classCount[static_cast<int>(data[i][0])-1]++;
    }
    maxClass = classCount[0] > classCount[1] ? 1 : 2;

 

    //normalize
    for (int i = 1; i <= numFeatures; i++)
    {
        normalize(i);
    }

    // if(featureSubset.size() == 0 && numFeatures == 10){
    //     writeToFile("normalizedDataSmall.txt");
    // }
    // else if(featureSubset.size() == 0){
    //     writeToFile("normalizedDataLarge.txt");
    // }
    
    std::clock_t end  = std::clock();
    double timeTaken = (end - start)/(double)CLOCKS_PER_SEC;
}

// Predict the class label for a given feature vector
// This is for a user to use to predict label for new data
int Classifier::test(vector<double> &features)
{
     if(featureSubset.size() == 0){
        return maxClass;
    }
    // Normalize the features
    normalizeFeatures(features);

    return nn(features);
}

// Predict the class label for a given id
// This is for the validator to use to predict label for the test data
int Classifier::test(int id)
{
     if(featureSubset.size() == 0){
        return maxClass;
    }
    // No need to normalize the features since they are already normalized
    if (id < 0 || id >= data.size())
    {
        throw out_of_range("ID is out of bounds!");
        return -1;
    }
    return nn(id);
}

//---------------------------------------
//           PRIVATE HELPERS
//---------------------------------------

// Calculate the Euclidean distance between two data points
double Classifier::distance(const vector<double> &features, int row) const
{   
    //cout << featureSubset.size() << endl;
    // make sure row is in range
    if (row < 0 || row >= data.size())
    {
        throw out_of_range("id2 is out of bounds");
    }

    const vector<double> &datapoint = data[row];

    // make sure feat vec is in range
    for (int i : featureSubset)
    {
        if (i < 1 || i >= datapoint.size())
        {
            throw out_of_range("featureSubset index is out of bounds");
        }
    }

    double sum = 0.0;
    // for each feature that we're caluclating based on
    for (int i = 0; i < featureSubset.size(); i++)
    {
        int featindex = featureSubset[i]; // current feature we're comparing
        if (featindex - (datapoint.size() - features.size()) < 0 ||
            featindex - (datapoint.size() - features.size()) >= features.size())
        {
            throw out_of_range("Index adjustment out of bounds");
        }

        // calculate diff between feature value
        double diff = features[featindex - (datapoint.size() - features.size())] -
                      datapoint[featindex];
        sum += diff * diff;
    }

    return sqrt(sum);
}

// Normalize the data
void Classifier::normalize(int col)
{
    // Find the minimum and maximum values in the specified column
    double minVal = data[0][col];
    double maxVal = data[0][col];
    for (const auto &featureVector : data)
    {
        double value = featureVector[col];
        if (value < minVal)
        {
            minVal = value;
        }
        if (value > maxVal)
        {
            maxVal = value;
        }
    }
    vector<double> temp;
    temp.push_back(minVal);
    temp.push_back(maxVal);
    normalizingData.push_back(temp);

    // Normalize the values in the specified column
    for (auto &featureVector : data)
    {
        double value = featureVector[col];
        double normalizedValue = (value - minVal) / (maxVal - minVal);
        featureVector[col] = normalizedValue;
    }
}
int Classifier::nn(vector<double> &features, int excludeRow)
{
    int nnclass = -1;
    double minDist = 1;

    for (size_t row = 0; row < data.size(); ++row)
    {
        if (row != excludeRow)
        {
            double temp = distance(features, row);
            if (temp < minDist)
            {
                minDist = temp;
                nnclass = static_cast<int>(data[row][0]);
            }
        }
    }
    return nnclass;
}

int Classifier::nn(int row)
{
    if (row < 0 || row >= data.size())
    {
        throw out_of_range("Row index is out of bounds");
    }
    // features of that row
    vector<double> features(data[row].begin() + 1, data[row].end());
    return nn(features, row);
}

// Normalize the features
void Classifier::normalizeFeatures(vector<double> &features)
{
    for (int i = 0; i < numFeatures; i++)
    {
        double value = features[i];
        double normalizedValue = (value - normalizingData[i][0]) /
                                 (normalizingData[i][1] - normalizingData[i][0]);
        features[i] = normalizedValue;
    }
}

// Function to print a 2D vector with the index as the id
void Classifier::print()
{
    cout << "--------------------------------------------------------------------"
            "-------------------------"
         << endl;
    printf("ID\tClass\t");
    for (int i = 1; i <= numFeatures; i++)
    {
        printf("F_%d\t", i);
    }
    printf("\n");
    cout << "--------------------------------------------------------------------"
            "-------------------------"
         << endl;

    for (int i = 0; i < data.size(); i++)
    {
        printf("%d\t", i);
        for (int j = 0; j < data[i].size(); j++)
        {
            printf("%.2f\t", data[i][j]);
        }
        cout << endl;
    }
}

int Classifier::getNumFeatures() { return numFeatures; }

int Classifier::getNumDataPoints() { return data.size(); }

const vector<vector<double> > &Classifier::getData() const { return data; }