#ifndef MERGE_SEQUENCE_H
#define MERGE_SEQUENCE_H

#include <vector>
#include <utility>

using namespace std;

// Structure to hold both merged sequence and remaining duplicates
struct MergeSequenceResult {  // Changed from MergeResult to MergeSequenceResult
    vector<int> sequence;    // Main sequence with no adjacent duplicates
    vector<int> duplicates;  // Numbers that couldn't be placed
};

// Main function to find maximum consecutive unique sequence
vector<int> findMaxConsecutiveMerge(const vector<int>& numbers);

// Helper functions
MergeSequenceResult mergeSortedSequences(const vector<int>& left, const vector<int>& right);
vector<int> mergeSort(const vector<int>& arr, int start, int end);
bool canPlaceAdjacent(int num, int prev, int next);

#endif