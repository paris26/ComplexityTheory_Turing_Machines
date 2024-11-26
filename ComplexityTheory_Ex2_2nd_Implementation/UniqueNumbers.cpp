#include "UniqueNumbers.h"
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

UniqueNumbersResult findUniqueNumbers(const vector<int>& numbers) {

    unordered_set<int> uniqueSet;
    vector<int> uniqueNumbers;
    
    for (int num : numbers) {
        uniqueSet.insert(num);
    }
    
    uniqueNumbers.assign(uniqueSet.begin(), uniqueSet.end());
    
    sort(uniqueNumbers.begin(), uniqueNumbers.end());
    
    return {uniqueNumbers, static_cast<int>(uniqueSet.size())};
}

void printUniqueNumbers(const vector<int>& numbers) {
    UniqueNumbersResult result = findUniqueNumbers(numbers);
    
    cout << "Unique numbers (" << result.count << " numbers): ";
    for (int num : result.uniqueNumbers) {
        cout << num << " ";
    }
    cout << endl;
}