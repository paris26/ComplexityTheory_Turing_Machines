#include "UniqueNumbers.h"
#include "OptimizedSequence.h"
#include "BruteForceSequence.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void printSequenceInfo(const string& name, const vector<int>& sequence) {
    cout << name << ": ";
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;
    
    // Print the consecutive differences
    cout << "Differences: ";
    for (size_t i = 1; i < sequence.size(); i++) {
        cout << abs(sequence[i] - sequence[i-1]) << " ";
    }
    cout << endl;
}

int main() {
    // Test vector with some numbers including duplicates
    vector<int> numbers = {1, 5, 2, 1, 4, 3, 2, 5, 8, 9, 7, 6};
    
    // First find and print unique numbers
    cout << "Finding unique numbers..." << endl;
    printUniqueNumbers(numbers);
    
    // Get the unique numbers result
    UniqueNumbersResult uniqueResult = findUniqueNumbers(numbers);
    
    cout << "\nComparing algorithms..." << endl;
    
    // Test optimized version
    auto start = high_resolution_clock::now();
    vector<int> optimalSequence = findOptimalSequence(uniqueResult.uniqueNumbers);
    auto stop = high_resolution_clock::now();
    auto optimizedDuration = duration_cast<microseconds>(stop - start);
    
    // Test brute force version
    start = high_resolution_clock::now();
    vector<int> bruteForceSequence = findOptimalSequenceBruteForce(uniqueResult.uniqueNumbers);
    stop = high_resolution_clock::now();
    auto bruteForceDuration = duration_cast<microseconds>(stop - start);
    
    // Print results
    cout << "\nResults:" << endl;
    cout << "--------" << endl;
    
    printSequenceInfo("Optimized sequence", optimalSequence);
    cout << "Time taken: " << optimizedDuration.count() << " microseconds" << endl;
    
    cout << "\n";
    
    printSequenceInfo("Brute force sequence", bruteForceSequence);
    cout << "Time taken: " << bruteForceDuration.count() << " microseconds" << endl;
    
    return 0;
}