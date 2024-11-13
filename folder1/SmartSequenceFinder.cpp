#include "SmartSequenceFinder.h"
#include <algorithm>
#include <unordered_set>

vector<int> SmartSequenceFinder::getFrequencyBasedArrangement(const vector<int>& numbers) {
    // Count frequencies
    unordered_map<int, int> freq;
    for (int num : numbers) {
        freq[num]++;
    }
    
    // Create pairs of (number, frequency)
    vector<pair<int, int>> numFreq;
    for (const auto& pair : freq) {
        numFreq.push_back({pair.first, pair.second});
    }
    
    // Sort by frequency (ascending) and then by value
    sort(numFreq.begin(), numFreq.end(), 
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second < b.second || (a.second == b.second && a.first < b.first);
         });
    
    // Create initial arrangement
    vector<int> result;
    for (const auto& pair : numFreq) {
        for (int i = 0; i < pair.second; i++) {
            result.push_back(pair.first);
        }
    }
    
    return result;
}

int SmartSequenceFinder::findLongestSequence(const vector<int>& arr) {
    int maxLength = 0;
    int currentLength = 0;
    unordered_set<int> currentSet;
    
    for (size_t i = 0; i < arr.size(); i++) {
        if (currentSet.find(arr[i]) == currentSet.end()) {
            currentLength++;
            currentSet.insert(arr[i]);
        } else {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
            currentSet.clear();
            currentSet.insert(arr[i]);
        }
    }
    
    return max(maxLength, currentLength);
}

vector<int> SmartSequenceFinder::slidingWindowOptimize(vector<int>& numbers) {
    int n = numbers.size();
    vector<int> bestArrangement = numbers;
    int maxLen = findLongestSequence(numbers);
    
    // Try different window sizes
    for (int windowSize = 2; windowSize <= min(8, n); windowSize++) {
        for (int start = 0; start < n - windowSize + 1; start++) {
            // Try all permutations within the window
            vector<int> temp = numbers;
            sort(temp.begin() + start, temp.begin() + start + windowSize);
            
            do {
                int currentLen = findLongestSequence(temp);
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    bestArrangement = temp;
                }
            } while (next_permutation(temp.begin() + start, 
                                    temp.begin() + start + windowSize));
        }
    }
    
    return bestArrangement;
}

vector<int> SmartSequenceFinder::findMaxConsecutiveUnique(const vector<int>& numbers) {
    if (numbers.size() <= 1) return numbers;
    
    // Step 1: Get frequency-based arrangement
    vector<int> arrangement = getFrequencyBasedArrangement(numbers);
    
    // Step 2: Apply sliding window optimization
    vector<int> optimized = slidingWindowOptimize(arrangement);
    
    // Step 3: If the sequence is small enough, try to improve it further
    if (optimized.size() <= 10) {
        vector<int> temp = optimized;
        int bestLen = findLongestSequence(optimized);
        
        do {
            int currentLen = findLongestSequence(temp);
            if (currentLen > bestLen) {
                bestLen = currentLen;
                optimized = temp;
            }
        } while (next_permutation(temp.begin(), temp.end()));
    }
    
    return optimized;
}

int SmartSequenceFinder::countConsecutiveDifferent(const vector<int>& arr) {
    if (arr.empty()) return 0;
    
    int maxLen = 1;
    int currentLen = 1;
    unordered_set<int> seen;
    seen.insert(arr[0]);
    
    for (size_t i = 1; i < arr.size(); i++) {
        if (seen.find(arr[i]) == seen.end()) {
            currentLen++;
            seen.insert(arr[i]);
        } else {
            maxLen = max(maxLen, currentLen);
            currentLen = 1;
            seen.clear();
            seen.insert(arr[i]);
        }
    }
    
    return max(maxLen, currentLen);
}