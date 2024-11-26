#ifndef ALTERNATIVE_FINDER_H
#define ALTERNATIVE_FINDER_H

#include <vector>
#include <string>
using namespace std;

// Helper structure to store merge sort results
struct MergeSortResult {
    vector<string> primaryArray;  // Array with numbers and # markers
    vector<int> duplicatesArray;  // Array storing duplicate numbers
};

// Helper function to convert int to string with # markers
string numberToMarkedString(int num);

// Helper function to extract number from marked string
int extractNumber(const string& markedString);

// Count consecutive unique numbers in sequence
int countConsecutiveUnique(const vector<int>& arr);

// Merge sort helper functions
MergeSortResult mergeWithDuplicateDetection(
    const vector<string>& left, const vector<int>& leftDupes,
    const vector<string>& right, const vector<int>& rightDupes
);

MergeSortResult mergeSortWithDuplicates(const vector<int>& arr, int start, int end);

// Main function to find maximum consecutive unique sequence
vector<int> findMaxConsecutiveUnique(const vector<int>& numbers);

// Function to reconstruct final sequence
vector<int> reconstructSequence(
    const vector<string>& primaryArray,
    const vector<int>& duplicatesArray
);

#endif