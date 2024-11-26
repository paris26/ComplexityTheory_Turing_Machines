#ifndef OPTIMAL_SEQUENCE_H
#define OPTIMAL_SEQUENCE_H

#include <vector>

using namespace std;

// Main function to find optimal sequence without adjacent duplicates
vector<int> findOptimalSequence(vector<int>& numbers);

// Helper function to validate if a sequence has no adjacent duplicates
bool validateSequence(const vector<int>& seq);

// Test function with various test cases
void testOptimalSequence();

#endif // OPTIMAL_SEQUENCE_H