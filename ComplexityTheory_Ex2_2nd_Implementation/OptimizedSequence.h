#ifndef OPTIMIZED_SEQUENCE_H
#define OPTIMIZED_SEQUENCE_H

#include <vector>

using namespace std;

/**
 * Finds the optimal sequence of unique numbers that maximizes the length of
 * consecutive differences. Uses a greedy approach for optimization.
 * 
 * @param uniqueNumbers Vector of unique numbers to arrange
 * @return Vector containing the optimal sequence
 */
vector<int> findOptimalSequence(const vector<int>& uniqueNumbers);

#endif