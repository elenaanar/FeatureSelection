#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <pthread.h> 

using namespace std;

void* run(vector<string> data){
    string command = "./project " + data[0] + " " + data[1]+ " > " + data[2];
    int result = system(command.c_str());
    if (result == 0){
        cout << "Success" << endl;
    } else {
        cout << "Failed" << endl;
    }

}
int main() {
    system("g++ main.cpp src/Search.cpp src/Validator.cpp src/Classifier.cpp -o project");
    vector<vector<string> > data;
    //{{"data/small14.txt", "1", "output1.txt"}, {"data/small14.txt", "2", "output2.txt"}, {"data/large14.txt", "1", "output3.txt"}, {"data/large14.txt", "2", "output4.txt"}};
    vector<string> temp;
    temp.push_back("data/small14.txt");
    temp.push_back("1"); //forward
    temp.push_back("output/output1.txt");
    data.push_back(temp);
    temp.clear();
    temp.push_back("data/small14.txt");
    temp.push_back("2"); //backward
    temp.push_back("output/output2.txt");
    data.push_back(temp);
    temp.clear();
    temp.push_back("data/large14.txt");
    temp.push_back("1"); //forward
    temp.push_back("output/output3.txt");
    data.push_back(temp);
    temp.clear();
    temp.push_back("data/large14.txt");
    temp.push_back("2"); //backward
    temp.push_back("output/output4.txt");
    data.push_back(temp);
    temp.clear();

    for(int i = 0; i < data.size(); i++){
        run(data[i]);
    }
    
    return 0;
}