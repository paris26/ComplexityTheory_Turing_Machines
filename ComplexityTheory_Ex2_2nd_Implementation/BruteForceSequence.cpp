#include "BruteForceSequence.h"
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Helper function to evaluate the quality of a sequence
 * Returns the length of the longest valid subsequence
 */
int evaluateSequenceBruteForce(const vector<int>& sequence) {
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

vector<int> findOptimalSequenceBruteForce(const vector<int>& uniqueNumbers) {
    if (uniqueNumbers.empty()) return vector<int>();
    
    // Create a working copy that we'll permute
    vector<int> currentPermutation = uniqueNumbers;
    vector<int> bestSequence = currentPermutation;
    int bestScore = evaluateSequenceBruteForce(currentPermutation);
    
    // Try all possible permutations
    while (next_permutation(currentPermutation.begin(), currentPermutation.end())) {
        int currentScore = evaluateSequenceBruteForce(currentPermutation);
        if (currentScore > bestScore) {
            bestScore = currentScore;
            bestSequence = currentPermutation;
        }
    }
    
    // Try one more time with the sorted sequence (first permutation)
    currentPermutation = uniqueNumbers;
    sort(currentPermutation.begin(), currentPermutation.end());
    int currentScore = evaluateSequenceBruteForce(currentPermutation);
    if (currentScore > bestScore) {
        bestScore = currentScore;
        bestSequence = currentPermutation;
    }
    
    return bestSequence;
}