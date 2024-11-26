#include "test_framework.h"
#include "AlternativeSequenceFinder.h"
#include "sequence_finder.h"
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std::chrono;

int TestFramework::countMaxConsecutiveDifferent(const vector<int>& arr) {
    if (arr.empty()) return 0;
    
    int maxLen = 1;
    int currentLen = 1;
    
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i-1]) {
            currentLen++;
            maxLen = max(maxLen, currentLen);
        } else {
            currentLen = 1;
        }
    }
    return maxLen;
}

void TestFramework::printArray(const vector<int>& arr, const string& message) {
    cout << message;
    for(int num : arr) cout << num << " ";
    cout << "\n";
}

TestFramework::TestResult::TestResult(vector<int> sol, long long time) 
    : solution(sol), timeTaken(time) {
    maxConsecutive = countMaxConsecutiveDifferent(sol);
}

void TestFramework::compareResults(const vector<TestResult>& results, 
                                 const vector<string>& methodNames) {
    cout << "\nComparison Results:\n";
    cout << setw(25) << left << "Method" 
         << setw(20) << "Time (μs)" 
         << setw(25) << "Max Consecutive Length" 
         << "Sequence\n";
    cout << string(100, '-') << "\n";
    
    for (size_t i = 0; i < results.size(); i++) {
        cout << setw(25) << left << methodNames[i]
             << setw(20) << results[i].timeTaken
             << setw(25) << results[i].maxConsecutive;
        printArray(results[i].solution, "");
    }
}

vector<int> TestFramework::generateRandomSequence(const GenerationParams& params) {
    vector<int> sequence;
    random_device rd;
    mt19937 gen(rd());
    
    // Generate uniform distribution for values
    uniform_int_distribution<> value_dist(params.minValue, params.maxValue);
    
    // First, generate unique numbers
    unordered_map<int, int> number_count;
    while (sequence.size() < params.sequenceLength) {
        int num = value_dist(gen);
        if (number_count[num] < params.maxDuplicates) {
            sequence.push_back(num);
            number_count[num]++;
        }
    }
    
    // Shuffle the sequence
    shuffle(sequence.begin(), sequence.end(), gen);
    
    return sequence;
}

void TestFramework::testSequence(const vector<int>& numbers, const string& testName) {
    cout << "\nTest Case: " << testName << "\n";
    cout << "Input size: " << numbers.size() << " elements\n";
    printArray(numbers, "Input sequence: ");
    
    vector<TestResult> results;
    vector<string> methodNames;
    
    // Only run brute force for small sequences
    if (numbers.size() <= BRUTE_FORCE_THRESHOLD) {
        cout << "Running Brute Force method...\n";
        auto start = high_resolution_clock::now();
        vector<int> numbersCopy = numbers;
        vector<int> bruteForceSolution = SequenceFinder::bruteForceMaxConsecutive(numbersCopy);
        auto end = high_resolution_clock::now();
        results.emplace_back(bruteForceSolution, 
                           duration_cast<microseconds>(end - start).count());
        methodNames.push_back("Brute Force");
    } else {
        cout << "Skipping Brute Force (sequence length > " << BRUTE_FORCE_THRESHOLD << ")\n";
    }
    
    // Always run merge-sort based method
    cout << "Running Merge-Sort Based method...\n";
    auto start = high_resolution_clock::now();
    vector<int> mergeSortSolution = AlternativeSequenceFinder::findMaxConsecutiveUnique(numbers);
    auto end = high_resolution_clock::now();
    results.emplace_back(mergeSortSolution,
                        duration_cast<microseconds>(end - start).count());
    methodNames.push_back("Merge-Sort Based");
    
    compareResults(results, methodNames);
}

void TestFramework::runTestSuite() {
    cout << "=== Random Sequence Test Generator ===\n";
    cout << "This program will generate random sequences and test both algorithms.\n";
    cout << "Brute force will only run for sequences up to " 
         << BRUTE_FORCE_THRESHOLD << " elements.\n\n";

    while(true) {
        cout << "\nTest Generation Options:\n";
        cout << "1. Generate and test random sequence\n";
        cout << "2. Exit\n";
        cout << "Enter your choice (1-2): ";
        
        int choice;
        cin >> choice;
        
        if (choice == 2) {
            cout << "Exiting program.\n";
            return;
        }
        
        if (choice == 1) {
            GenerationParams params;
            
            cout << "\nEnter sequence parameters:\n";
            cout << "Length of sequence: ";
            cin >> params.sequenceLength;
            
            cout << "Minimum value: ";
            cin >> params.minValue;
            
            cout << "Maximum value: ";
            cin >> params.maxValue;
            
            cout << "Maximum duplicates per number: ";
            cin >> params.maxDuplicates;
            
            if (params.sequenceLength <= 0 || 
                params.maxValue < params.minValue || 
                params.maxDuplicates <= 0) {
                cout << "Invalid parameters! Please try again.\n";
                continue;
            }
            
            vector<int> sequence = generateRandomSequence(params);
            
            stringstream ss;
            ss << "Random sequence (Length=" << params.sequenceLength 
               << ", Range=[" << params.minValue << "," << params.maxValue << "]"
               << ", MaxDupes=" << params.maxDuplicates << ")";
               
            testSequence(sequence, ss.str());
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}