// sequence_finder.cpp
#include "sequence_finder.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int SequenceFinder::countConsecutiveDifferent(const vector<int>& arr) {
    if (arr.empty()) return 0;
    
    int maxLen = 1;
    unordered_set<int> seen;
    int left = 0;
    
    for (int right = 0; right < arr.size(); right++) {
        while (seen.find(arr[right]) != seen.end()) {
            seen.erase(arr[left]);
            left++;
        }
        seen.insert(arr[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}

vector<int> SequenceFinder::bruteForceMaxConsecutive(vector<int>& numbers) {
    vector<int> bestArrangement = numbers;
    int maxLength = countConsecutiveDifferent(numbers);

    sort(numbers.begin(), numbers.end());
    do {
        int currentLength = countConsecutiveDifferent(numbers);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            bestArrangement = numbers;
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return bestArrangement;
}

vector<int> SequenceFinder::optimizedMaxConsecutive(const vector<int>& numbers) {
    if (numbers.empty()) return {};
    
    vector<int> result;
    unordered_map<int, int> frequency;
    
    // Count frequencies
    for (int num : numbers) {
        frequency[num]++;
    }
    
    // Convert to vector for sorting
    vector<pair<int, int>> numFreq;
    for (const auto& pair : frequency) {
        numFreq.push_back({pair.first, pair.second});
    }
    
    // Create initial arrangement
    sort(numFreq.begin(), numFreq.end());
    for (const auto& pair : numFreq) {
        for (int i = 0; i < pair.second; i++) {
            result.push_back(pair.first);
        }
    }
    
    // Find the best rotation
    int maxLen = 0;
    int bestStart = 0;
    int n = result.size();
    
    for (int start = 0; start < n; start++) {  // Fixed: start from 0
        int currentLen = 0;
        unordered_set<int> window;
        
        for (int i = 0; i < n && window.find(result[(start + i) % n]) == window.end(); i++) {
            window.insert(result[(start + i) % n]);
            currentLen++;
        }
        
        if (currentLen > maxLen) {
            maxLen = currentLen;
            bestStart = start;
        }
    }
    
    // Create the final arrangement
    vector<int> optimized;
    for (int i = 0; i < n; i++) {
        optimized.push_back(result[(bestStart + i) % n]);
    }
    
    return optimized;
}

void SequenceFinder::runPartB(const vector<int>& numbers) {
    vector<int> numbersCopy1 = numbers;
    vector<int> numbersCopy2 = numbers;

    cout << "\nPart B Results:\n";
    cout << "\nBrute Force Solution:\n";
    vector<int> bruteForceSolution = bruteForceMaxConsecutive(numbersCopy1);
    cout << "Maximum consecutive different sequence length: " 
         << countConsecutiveDifferent(bruteForceSolution) << "\n";
    cout << "Arrangement: ";
    for (int num : bruteForceSolution) cout << num << " ";
    cout << "\n";

    cout << "\nOptimized Solution:\n";
    vector<int> optimizedSolution = optimizedMaxConsecutive(numbersCopy2);
    cout << "Maximum consecutive different sequence length: " 
         << countConsecutiveDifferent(optimizedSolution) << "\n";
    cout << "Arrangement: ";
    for (int num : optimizedSolution) cout << num << " ";
    cout << "\n";
}