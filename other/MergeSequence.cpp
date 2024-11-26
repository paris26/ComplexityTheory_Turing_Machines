#include "MergeSequence.h"
#include <algorithm>
#include <unordered_set>

using namespace std;

bool canPlaceAdjacent(int num, int prev, int next) {
    return (prev == -1 || prev != num) && (next == -1 || next != num);
}

MergeSequenceResult mergeSortedSequences(const vector<int>& left, const vector<int>& right) {
    vector<int> merged;
    vector<int> duplicates;
    
    int i = 0, j = 0;
    int prev = -1;
    
    while (i < left.size() || j < right.size()) {
        int next = -1;
        if (i + 1 < left.size()) next = left[i + 1];
        else if (j < right.size()) next = right[j];
        
        if (i < left.size() && canPlaceAdjacent(left[i], prev, next)) {
            merged.push_back(left[i]);
            prev = left[i];
            i++;
        }
        else if (j < right.size() && canPlaceAdjacent(right[j], prev, next)) {
            merged.push_back(right[j]);
            prev = right[j];
            j++;
        }
        else {
            if (i < left.size()) {
                duplicates.push_back(left[i++]);
            }
            if (j < right.size()) {
                duplicates.push_back(right[j++]);
            }
        }
    }
    
    return {merged, duplicates};
}

vector<int> mergeSort(const vector<int>& arr, int start, int end) {
    // Handle empty array case
    if (arr.empty()) return {};
    
    // Handle invalid range
    if (start > end) return {};
    
    // Base case: single element
    if (start == end) {
        return {arr[start]};
    }
    
    // Recursive case
    int mid = start + (end - start) / 2;
    vector<int> left = mergeSort(arr, start, mid);
    vector<int> right = mergeSort(arr, mid + 1, end);
    
    // Merge results
    MergeSequenceResult result = mergeSortedSequences(left, right);
    
    // Try to insert duplicates where possible
    vector<int>& seq = result.sequence;
    for (int dup : result.duplicates) {
        bool placed = false;
        // Try to insert at beginning
        if (seq.empty() || seq[0] != dup) {
            seq.insert(seq.begin(), dup);
            placed = true;
        } else {
            // Try to insert between elements or at end
            for (size_t i = 0; i < seq.size(); i++) {
                bool canPlaceHere = true;
                if (i > 0 && seq[i-1] == dup) canPlaceHere = false;
                if (i < seq.size() && seq[i] == dup) canPlaceHere = false;
                
                if (canPlaceHere) {
                    seq.insert(seq.begin() + i, dup);
                    placed = true;
                    break;
                }
            }
        }
        // If we couldn't place it anywhere else, try at the end
        if (!placed && (seq.empty() || seq.back() != dup)) {
            seq.push_back(dup);
        }
    }
    
    return seq;
}

vector<int> findMaxConsecutiveMerge(const vector<int>& numbers) {
    if (numbers.empty()) return {};
    if (numbers.size() == 1) return numbers;
    
    return mergeSort(numbers, 0, numbers.size() - 1);
}