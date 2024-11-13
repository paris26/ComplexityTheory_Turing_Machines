#include "unique_numbers.h"
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> UniqueNumbersFinder::findUniqueNumbers(const vector<int>& numbers){
    unordered_map<int, int> count;
    vector<int> uniqueNumbers;

    for(int num : numbers){
        count[num]++;
    }

    for(const auto& pair : count){
        if(pair.second == 1){
            uniqueNumbers.push_back(pair.first);
        }
    }
    return uniqueNumbers;
}

void UniqueNumbersFinder::runPartA(const vector<int>& numbers){
    cout << "\nPart A Results:\n";
    vector<int> uniqueNumbers = findUniqueNumbers(numbers);
    cout << "Numbers that appear exactly once: " << uniqueNumbers.size() << "\n";
    cout << "These numbers are: ";
    for(int num : uniqueNumbers) {
        cout << num << " ";
    }
    cout << "\n";
}