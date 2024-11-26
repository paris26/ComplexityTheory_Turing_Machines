#include "sequence_finder.h"
#include "alternative_finder.h"
#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

void printArray(const vector<int>& arr, const string& message) {
    cout << message;
    for(int num : arr) cout << num << " ";
    cout << "\n";
}

// Function to run a test case with both algorithms
void runSmallTest(const vector<int>& numbers, const string& testName) {
    cout << "\n=== Test Case: " << testName << " ===\n";
    printArray(numbers, "Input: ");
    cout << "Input size: " << numbers.size() << " elements\n";
    
    // Run brute force
    auto start = high_resolution_clock::now();
    vector<int> numbersCopy = numbers;  // brute force modifies input
    vector<int> bruteForceSolution = bruteForceMaxConsecutive(numbersCopy);
    auto end = high_resolution_clock::now();
    auto bruteForceTime = duration_cast<microseconds>(end - start).count();
    
    // Get length of brute force sequence
    int bruteForceLength = countConsecutiveDifferent(bruteForceSolution);
    
    // Run merge sort
    start = high_resolution_clock::now();
    vector<int> mergeSortSolution = findMaxConsecutiveUnique(numbers);
    end = high_resolution_clock::now();
    auto mergeSortTime = duration_cast<microseconds>(end - start).count();
    
    // Get length of merge sort sequence
    int mergeSortLength = countConsecutiveUnique(mergeSortSolution);
    
    // Print results
    cout << "\nBrute Force Result:\n";
    cout << "Time: " << bruteForceTime << " microseconds\n";
    cout << "Sequence length: " << bruteForceLength << " consecutive unique numbers\n";
    printArray(bruteForceSolution, "Sequence: ");
    
    cout << "\nMerge Sort Result:\n";
    cout << "Time: " << mergeSortTime << " microseconds\n";
    cout << "Sequence length: " << mergeSortLength << " consecutive unique numbers\n";
    printArray(mergeSortSolution, "Sequence: ");
    cout << "---------------------------------------\n";
}

// Function to run a test case with only merge sort (for larger sequences)
void runLargeTest(const vector<int>& numbers, const string& testName) {
    cout << "\n=== Large Test Case: " << testName << " ===\n";
    printArray(numbers, "Input: ");
    cout << "Input size: " << numbers.size() << " elements\n";
    
    auto start = high_resolution_clock::now();
    vector<int> mergeSortSolution = findMaxConsecutiveUnique(numbers);
    auto end = high_resolution_clock::now();
    auto mergeSortTime = duration_cast<microseconds>(end - start).count();
    
    // Get length of merge sort sequence
    int mergeSortLength = countConsecutiveUnique(mergeSortSolution);
    
    cout << "\nMerge Sort Result:\n";
    cout << "Time: " << mergeSortTime << " microseconds\n";
    cout << "Sequence length: " << mergeSortLength << " consecutive unique numbers\n";
    printArray(mergeSortSolution, "Sequence: ");
    cout << "---------------------------------------\n";
}

int main() {
    cout << "Testing Maximum Consecutive Unique Sequence Algorithms\n\n";
    
    // Test cases for both algorithms
    cout << "Running tests for both algorithms (small cases)...\n";
    
    vector<int> test1 = {1, 2, 3, 7, 15, 15, 18};
    runSmallTest(test1, "Simple sequence with one duplicate");
    
    vector<int> test2 = {1, 1, 2, 2, 3, 3, 4, 4};
    runSmallTest(test2, "Multiple duplicates");
    
    vector<int> test3 = {5, 5, 4, 4, 3, 3, 2, 2, 1, 1};
    runSmallTest(test3, "Reverse sorted with duplicates");
    
    // Harder test cases (merge sort only)
    cout << "\nRunning harder tests (merge sort only)...\n";
    
    // Large sequence with periodic duplicates
    vector<int> test4;
    for(int i = 1; i <= 30; i++) {
        test4.push_back(i);
        if(i % 5 == 0) test4.push_back(i);  // duplicate every 5th number
    }
    runLargeTest(test4, "Periodic duplicates");
    
    // Large sequence with increasing duplicates
    vector<int> test5;
    for(int i = 1; i <= 20; i++) {
        for(int j = 0; j < (i+1)/5 + 1; j++) {  // more duplicates as i increases
            test5.push_back(i);
        }
    }
    runLargeTest(test5, "Increasing duplicates");
    
    // Large sequence with clustered duplicates
    vector<int> test6;
    for(int i = 1; i <= 25; i++) {
        test6.push_back(i);
        if(i >= 10 && i <= 15) {  // cluster of duplicates in the middle
            test6.push_back(i);
            test6.push_back(i);
        }
    }
    runLargeTest(test6, "Clustered duplicates");
    
    return 0;
}