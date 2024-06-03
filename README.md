# INSTRUCTIONS TO RUN CODE
```
g++ driver.cpp -o driver
./driver
```
Navigate to 'output' folder
output1.txt -- Trace for Small Dataset + Forward feature selection
output2.txt -- Trace for Small Dataset + Backward feature selection
output3.txt -- Trace for Large Dataset + Forward feature selection
output4.txt -- Trace for Large Dataset + Backward feature selection

# INSTRUCTIONS TO RUN CODE WITH CUSTOM DATASET
```
g++ main.cpp src/Search.cpp src/Validator.cpp src/Classifier.cpp -o project
./project 'path-to-dataset' 'algorithm-number'
```
Input 1 for Forward Feature Selection
Input 2 for Backward Feature Selection

# FeatureSelection

INTRODUCTION:
- Add forward feature selection
- Add backward feature selection
- Use randome evaluation function

PART 2:
- Add NN Classifier
- Add Leave-One-Out Cross Validator

PART 3:
- Integrated all parts together


