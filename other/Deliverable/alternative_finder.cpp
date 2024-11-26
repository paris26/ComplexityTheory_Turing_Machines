#include "alternative_finder.h"
#include <algorithm>
#include <sstream>

string numberToMarkedString(int num) {
    return "#" + to_string(num) + "#";
}

int extractNumber(const string& markedString) {
    string numStr = markedString.substr(1, markedString.length() - 2);
    return stoi(numStr);
}

int countConsecutiveUnique(const vector<int>& arr) {
    if (arr.empty()) return 0;
    
    int maxCount = 1;  // Length of current sequence
    int currentCount = 1;
    
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i-1]) {
            currentCount++;
            maxCount = max(maxCount, currentCount);
        } else {
            currentCount = 1;
        }
    }
    
    return maxCount;
}

MergeSortResult mergeWithDuplicateDetection(
    const vector<string>& left, const vector<int>& leftDupes,
    const vector<string>& right, const vector<int>& rightDupes) {
    
    vector<string> mergedPrimary;
    vector<int> mergedDupes;
    
    // First, merge the duplicates arrays
    mergedDupes.insert(mergedDupes.end(), leftDupes.begin(), leftDupes.end());
    mergedDupes.insert(mergedDupes.end(), rightDupes.begin(), rightDupes.end());
    
    // Sort duplicates in descending order
    sort(mergedDupes.begin(), mergedDupes.end(), greater<int>());
    
    // Merge the primary arrays while checking for additional duplicates
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        int leftNum = extractNumber(left[i]);
        int rightNum = extractNumber(right[j]);
        
        if (leftNum < rightNum) {
            mergedPrimary.push_back(left[i]);
            i++;
        }
        else if (leftNum > rightNum) {
            mergedPrimary.push_back(right[j]);
            j++;
        }
        else {
            // Found a duplicate
            mergedPrimary.push_back(left[i]);
            mergedDupes.push_back(leftNum);
            i++;
            j++;
        }
    }
    
    // Add remaining elements
    while (i < left.size()) {
        mergedPrimary.push_back(left[i++]);
    }
    while (j < right.size()) {
        mergedPrimary.push_back(right[j++]);
    }
    
    return {mergedPrimary, mergedDupes};
}

MergeSortResult mergeSortWithDuplicates(const vector<int>& arr, int start, int end) {
    if (start == end) {
        return {vector<string>{numberToMarkedString(arr[start])}, vector<int>{}};
    }
    
    int mid = start + (end - start) / 2;
    
    auto leftResult = mergeSortWithDuplicates(arr, start, mid);
    auto rightResult = mergeSortWithDuplicates(arr, mid + 1, end);
    
    return mergeWithDuplicateDetection(
        leftResult.primaryArray, leftResult.duplicatesArray,
        rightResult.primaryArray, rightResult.duplicatesArray
    );
}

vector<int> reconstructSequence(
    const vector<string>& primaryArray,
    const vector<int>& duplicatesArray) {
    
    vector<int> result;
    
    // First, extract all numbers from primary array
    for (const string& markedNum : primaryArray) {
        result.push_back(extractNumber(markedNum));
    }
    
    // Try to insert duplicates from largest to smallest
    for (int duplicate : duplicatesArray) {
        bool inserted = false;
        
        // Try each position in the result array
        for (size_t i = 0; i < result.size() && !inserted; i++) {
            // Check if we can insert here (no adjacent duplicates)
            bool canInsertHere = true;
            if (i > 0 && result[i-1] == duplicate) canInsertHere = false;
            if (i < result.size()-1 && result[i] == duplicate) canInsertHere = false;
            
            if (canInsertHere) {
                result.insert(result.begin() + i, duplicate);
                inserted = true;
            }
        }
        
        // If we couldn't insert in the middle, try at the end
        if (!inserted && result.back() != duplicate) {
            result.push_back(duplicate);
        }
    }
    
    return result;
}

vector<int> findMaxConsecutiveUnique(const vector<int>& numbers) {
    if (numbers.empty()) return {};
    
    // Perform merge sort with duplicate detection
    auto result = mergeSortWithDuplicates(numbers, 0, numbers.size() - 1);
    
    // Reconstruct the sequence
    return reconstructSequence(result.primaryArray, result.duplicatesArray);
}