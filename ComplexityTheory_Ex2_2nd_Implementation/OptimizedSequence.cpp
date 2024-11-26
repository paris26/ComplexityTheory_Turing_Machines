#include "OptimizedSequence.h"
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

/**
 * Helper function to evaluate the quality of a sequence
 * Returns the length of the longest valid subsequence
 */
int evaluateSequence(const vector<int>& sequence) {
    if (sequence.size() <= 1) return sequence.size();
    
    int maxLen = 1;
    int currentLen = 1;
    
    for (size_t i = 1; i < sequence.size(); i++) {
        if (abs(sequence[i] - sequence[i-1]) == 1) {
            currentLen++;
            maxLen = max(maxLen, currentLen);
        } else {
            currentLen = 1;
        }
    }
    
    return maxLen;
}

vector<int> findOptimalSequence(const vector<int>& uniqueNumbers) {
    if (uniqueNumbers.empty()) return vector<int>();
    
    // Create a working copy
    vector<int> numbers = uniqueNumbers;
    vector<int> bestSequence = numbers;
    int bestScore = evaluateSequence(numbers);
    
    // Using a greedy approach with local optimization
    // We'll try different starting points and build sequences
    for (size_t startIdx = 0; startIdx < numbers.size(); startIdx++) {
        vector<int> currentSequence;
        vector<bool> used(numbers.size(), false);
        
        // Start with the number at startIdx
        currentSequence.push_back(numbers[startIdx]);
        used[startIdx] = true;
        
        // Build the sequence greedily
        while (currentSequence.size() < numbers.size()) {
            int lastNum = currentSequence.back();
            int bestDiff = INT_MAX;
            int bestIdx = -1;
            
            // Find the best next number (closest to last number)
            for (size_t i = 0; i < numbers.size(); i++) {
                if (!used[i]) {
                    int diff = abs(numbers[i] - lastNum);
                    if (diff < bestDiff) {
                        bestDiff = diff;
                        bestIdx = i;
                    }
                }
            }
            
            if (bestIdx == -1) break;
            
            currentSequence.push_back(numbers[bestIdx]);
            used[bestIdx] = true;
        }
        
        // Evaluate this sequence
        int currentScore = evaluateSequence(currentSequence);
        if (currentScore > bestScore) {
            bestScore = currentScore;
            bestSequence = currentSequence;
        }
    }
    
    return bestSequence;
}