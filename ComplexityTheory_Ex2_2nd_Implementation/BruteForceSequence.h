#ifndef BRUTE_FORCE_SEQUENCE_H
#define BRUTE_FORCE_SEQUENCE_H

#include <vector>

using namespace std;

/**
 * Finds the optimal sequence of unique numbers by trying all possible permutations
 * and selecting the one with the longest sequence of consecutive differences.  
*/
vector<int> findOptimalSequenceBruteForce(const vector<int>& uniqueNumbers);

#endif