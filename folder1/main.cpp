#include "unique_numbers.h"
#include "sequence_finder.h"
#include "AlternativeSequenceFinder.h"
#include "SmartSequenceFinder.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void printArray(const vector<int>& arr, const string& message) {
    cout << message;
    for(int num : arr) cout << num << " ";
    cout << "\n";
}

struct TestResult {
    vector<int> solution;
    long long timeTaken;
    int maxConsecutive;
    
    TestResult(vector<int> sol, long long time) 
        : solution(sol), timeTaken(time) {
        maxConsecutive = SequenceFinder::countConsecutiveDifferent(sol);
    }
};

void compareResults(const vector<TestResult>& results, const vector<string>& methodNames) {
    cout << "\nComparison Results:\n";
    cout << setw(25) << left << "Method" 
         << setw(20) << "Time (μs)" 
         << setw(25) << "Max Consecutive Length" 
         << "Sequence\n";
    cout << string(80, '-') << "\n";
    
    for (size_t i = 0; i < results.size(); i++) {
        cout << setw(25) << left << methodNames[i]
             << setw(20) << results[i].timeTaken
             << setw(25) << results[i].maxConsecutive;
        printArray(results[i].solution, "");
    }
}

void testSequence(const vector<int>& numbers, const string& testName) {
    cout << "\nTest Case: " << testName << "\n";
    cout << "Input sequence: ";
    printArray(numbers, "");
    
    vector<TestResult> results;
    vector<string> methodNames = {
        "Brute Force",
        "Original Optimized",
        "Merge-Sort Based",
        "Smart Sequence"
    };
    
    // Test brute force
    auto start = high_resolution_clock::now();
    vector<int> numbersCopy = numbers;
    vector<int> bruteForceSolution = SequenceFinder::bruteForceMaxConsecutive(numbersCopy);
    auto end = high_resolution_clock::now();
    results.emplace_back(bruteForceSolution, 
                        duration_cast<microseconds>(end - start).count());
    
    // Test original optimized
    start = high_resolution_clock::now();
    vector<int> optimizedSolution = SequenceFinder::optimizedMaxConsecutive(numbers);
    end = high_resolution_clock::now();
    results.emplace_back(optimizedSolution,
                        duration_cast<microseconds>(end - start).count());
    
    // Test alternative method
    start = high_resolution_clock::now();
    vector<int> alternativeSolution = AlternativeSequenceFinder::findMaxConsecutiveUnique(numbers);
    end = high_resolution_clock::now();
    results.emplace_back(alternativeSolution,
                        duration_cast<microseconds>(end - start).count());
    
    // Test smart sequence method
    start = high_resolution_clock::now();
    vector<int> smartSolution = SmartSequenceFinder::findMaxConsecutiveUnique(numbers);
    end = high_resolution_clock::now();
    results.emplace_back(smartSolution,
                        duration_cast<microseconds>(end - start).count());
    
    compareResults(results, methodNames);
}

int main() {
    // Test case 1: Simple sequence with one duplicate
    vector<int> test1 = {1, 2, 3, 7, 15, 15, 18};
    testSequence(test1, "Simple sequence with one duplicate");

    // Test case 2: Sequence with multiple duplicates
    vector<int> test2 = {1, 1, 2, 2, 3, 3, 4, 4};
    testSequence(test2, "Multiple duplicates");

    // Test case 3: Already optimal sequence
    vector<int> test3 = {1, 2, 3, 4, 5};
    testSequence(test3, "Already optimal sequence");

    // Test case 4: Reverse sorted with duplicates
    vector<int> test4 = {5, 5, 4, 4, 3, 3, 2, 2, 1, 1};
    testSequence(test4, "Reverse sorted with duplicates");

    // Test case 5: Complex sequence with varied duplicates
    vector<int> test5 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9};
    testSequence(test5, "Complex sequence with varied duplicates");

    // Test case 6: Sequence with many duplicates of one number
    vector<int> test6 = {1, 2, 3, 2, 2, 2, 4, 5, 2, 6};
    testSequence(test6, "Many duplicates of one number");

    // Interactive testing
    char runCustomTest;
    cout << "\nWould you like to run a custom test? (y/n): ";
    cin >> runCustomTest;
    
    if (runCustomTest == 'y' || runCustomTest == 'Y') {
        int n;
        cout << "Enter the number of elements (n): ";
        cin >> n;
        
        vector<int> numbers(n);
        cout << "Enter " << n << " numbers:\n";
        for(int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        
        testSequence(numbers, "Custom test");
    }
    
    return 0;
}