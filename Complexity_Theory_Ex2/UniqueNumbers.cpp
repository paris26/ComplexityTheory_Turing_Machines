#include "UniqueNumbers.h"
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

UniqueNumbersResult findUniqueNumbers(const vector<int>& numbers) {
    /* 
        HASH SET - S(N)
        VECTOR - S(N)
    */
    unordered_set<int> uniqueSet;
    vector<int> uniqueNumbers;
    
    for (int num : numbers) {
        uniqueSet.insert(num);
    }
    
    uniqueNumbers.assign(uniqueSet.begin(), uniqueSet.end());
    
    // sorting the numbers - uneccessary - can delete
    sort(uniqueNumbers.begin(), uniqueNumbers.end());

    //second parameter is to return the count
    return {uniqueNumbers, static_cast<int>(uniqueSet.size())};
}


void printUniqueNumbers(const vector<int>& numbers) {
    UniqueNumbersResult result = findUniqueNumbers(numbers);
    
    //how many
    cout << "Unique numbers (" << result.count << " numbers): ";

    //printing them
    for (int num : result.uniqueNumbers) {
        cout << num << " ";
    }
    cout << endl;
}