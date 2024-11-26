#include "OptimalSequence.h"
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> findOptimalSequence(vector<int>& numbers) {
    if (numbers.empty()) return {};
    
    // Step 1: Count frequencies - O(n)
    unordered_map<int, int> freq;
    for (int num : numbers) {
        freq[num]++;
    }
    
    // Step 2: Create pairs of (number, frequency) and sort by frequency
    // we need to put it inside a pair to sort it
    vector<pair<int, int>> numFreq;
    for (const auto& [num, count] : freq) {
        numFreq.push_back({num, count});
    }

    // we made a pair to sort with given c++ function
    // 1 - compare frequencies 
    // 2 - if frequencies equal compare numbers
    sort(numFreq.begin(), numFreq.end(),
         [](const auto& a, const auto& b) {
             return a.second > b.second || (a.second == b.second && a.first < b.first);
         });
    
    // Step 3: Build sequence using two arrays 
    vector<int> seq1, seq2;
    //create a flag to interchangeably fill elements
    bool useSeq1 = true;
    
    // Place most frequent elements alternately in two sequences
    for (const auto& [num, count] : numFreq) {
        for (int i = 0; i < count; i++) {
            if (useSeq1) {
                // either empty or previous not
                if (seq1.empty() || seq1.back() != num) {
                    seq1.push_back(num);
                    useSeq1 = false;
                }
            } else {
                if (seq2.empty() || seq2.back() != num) {
                    seq2.push_back(num);
                    useSeq1 = true;
                }
            }
        }
    }
    
    // Step 4: Merge sequences optimally - O(n)
    vector<int> result;
    // the length of the first and the length of the second
    result.reserve(seq1.size() + seq2.size());
    
    // Interleave sequences to avoid adjacency
    int i = 0, j = 0;
    while (i < seq1.size() && j < seq2.size()) {
        // Try to add from seq1 first
        if (result.empty() || result.back() != seq1[i]) {
            result.push_back(seq1[i++]);
        }
        // Then try to add from seq2
        else if (result.back() != seq2[j]) {
            result.push_back(seq2[j++]);
        }
        // If neither works, move forward in seq1
        else {
            i++;
        }
    }
    
    // Add remaining elements if they don't create adjacency
    while (i < seq1.size()) {
        if (result.empty() || result.back() != seq1[i]) {
            result.push_back(seq1[i]);
        }
        i++;
    }
    while (j < seq2.size()) {
        if (result.empty() || result.back() != seq2[j]) {
            result.push_back(seq2[j]);
        }
        j++;
    }
    
    return result;
}

// bool validateSequence(const vector<int>& seq) {
//     for (int i = 1; i < seq.size(); i++) {
//         if (seq[i] == seq[i-1]) return false;
//     }
//     return true;
// }
