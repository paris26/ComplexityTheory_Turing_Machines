#ifndef ALTERNATIVE_SEQUENCE_FINDER_H
#define ALTERNATIVE_SEQUENCE_FINDER_H

#include <vector>
#include <string>
using namespace std;

class AlternativeSequenceFinder {
private:
    // Helper structure to store merge sort results
    struct MergeSortResult {
        vector<string> primaryArray;  // Array with numbers and # markers
        vector<int> duplicatesArray;  // Array storing duplicate numbers
    };

    // Merge sort helper functions
    static MergeSortResult mergeWithDuplicateDetection(
        const vector<string>& left, const vector<int>& leftDupes,
        const vector<string>& right, const vector<int>& rightDupes
    );
    
    static MergeSortResult mergeSortWithDuplicates(const vector<int>& arr, int start, int end);
    
    // Helper function to convert int to string with # markers
    static string numberToMarkedString(int num);
    
    // Helper function to extract number from marked string
    static int extractNumber(const string& markedString);

public:
    // Main function to find maximum consecutive unique sequence
    static vector<int> findMaxConsecutiveUnique(const vector<int>& numbers);
    
    // Function to reconstruct final sequence
    static vector<int> reconstructSequence(
        const vector<string>& primaryArray,
        const vector<int>& duplicatesArray
    );
};

#endif
