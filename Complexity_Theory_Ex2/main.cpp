#include "BruteForceSequence.h"
#include "OptimizedSequence.h"
#include "OptimalSequence.h"
#include "UniqueNumbers.h"
#include "helper.h"
#include <iomanip>
#include <iostream> 
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void printArray(const vector<int>& arr, const string& message) {
    cout << message;
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void printResults(const string& algorithmName, long long time, int length, const vector<int>& sequence) {
    cout << "\n" << algorithmName << " Result:\n";
    cout << "Time: " << time << " microseconds\n";
    cout << "Sequence length: " << length;
    if (algorithmName != "Brute Force") cout << "";
    cout << endl;
    printArray(sequence, "Sequence: ");
}

void runTest(const vector<int>& numbers, const string& testcase) {
    cout << "\n========= Test Case: " << testcase << " ==========\n";
    printArray(numbers, "Input: ");
    cout << "Input Size: " << numbers.size() << " elements\n";

    // Unique numbers analysis
    UniqueNumbersResult uniqueResult = findUniqueNumbers(numbers);
    cout << "\nUnique Numbers Analysis:\n";
    cout << "Total unique numbers: " << uniqueResult.count << "\n";
    printArray(uniqueResult.uniqueNumbers, "Unique sequence: ");

    vector<int> solution;
    long long executionTime;
    int sequenceLength;

    // Run brute force for small inputs only
    if(numbers.size() <= 10) {
        auto start = high_resolution_clock::now();
        vector<int> numbersCopy = numbers;
        solution = BruteForce(numbersCopy);
        auto end = high_resolution_clock::now();
        executionTime = duration_cast<microseconds>(end-start).count();
        sequenceLength = countValidSequence(solution);
        printResults("Brute Force", executionTime, sequenceLength, solution);
    }

    // Run optimized solution
    auto startOpt = high_resolution_clock::now();
    solution = findMaxConsecutiveUnique(numbers);
    auto endOpt = high_resolution_clock::now();
    executionTime = duration_cast<microseconds>(endOpt-startOpt).count();
    sequenceLength = countValidSequence(solution);
    printResults("Optimized", executionTime, sequenceLength, solution);

    // Run optimal solution
    auto startOptimal = high_resolution_clock::now();
    vector<int> numbersCopy = numbers;  
    solution = findOptimalSequence(numbersCopy);
    auto endOptimal = high_resolution_clock::now();
    executionTime = duration_cast<microseconds>(endOptimal-startOptimal).count();
    sequenceLength = countValidSequence(solution);
    printResults("Optimal", executionTime, sequenceLength, solution);
    
    cout << "\n---------------------------------------\n";
}

vector<int> generateRandomSequence(int size, int maxNum) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, maxNum);
    
    vector<int> sequence;
    for(int i = 0; i < size; i++) {
        sequence.push_back(dis(gen));
    }
    return sequence;
}

int main() { 
    cout << "Testing Maximum Consecutive Unique Sequence Algorithms\n\n";
    
    // Test case 1: Simple sequence with one duplicate
    vector<int> test1 = {1, 2, 3, 7, 15, 15, 18};
    runTest(test1, "Simple sequence with one duplicate");

    // Test case 2: Sequence with multiple duplicates
    vector<int> test2 = {1, 1, 2, 2, 3, 3, 4, 4};
    runTest(test2, "Multiple duplicates");

    // Test case 3: Already unique sequence
    vector<int> test3 = {1, 3, 5, 7, 9};
    runTest(test3, "Already unique sequence");

    // Test case 4: Larger sequence with pattern
    vector<int> test4;
    for(int i = 1; i <= 20; i++) {
        test4.push_back(i);
        test4.push_back(i);
    }
    runTest(test4, "Larger sequence with duplicates (pattern)");

    // Test case 5: Empty sequence
    vector<int> test5;
    runTest(test5, "Empty sequence");

    // Test case 6: Single element
    vector<int> test6 = {42};
    runTest(test6, "Single element");

    // Test case 7: All same elements
    vector<int> test7(5, 5);  // More efficient initialization
    runTest(test7, "All same elements");

    // Test case 8: Random sequence with duplicates
    vector<int> test8 = {8, 3, 8, 4, 1, 2, 1, 4, 7, 9};
    runTest(test8, "Random sequence with duplicates");

    // Test case 9: Large random sequence
    vector<int> test9 = generateRandomSequence(100, 50);
    runTest(test9, "Large random sequence");

    return 0;
}