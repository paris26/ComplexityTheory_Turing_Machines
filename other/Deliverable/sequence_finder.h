// sequence_finder.h
#ifndef SEQUENCE_FINDER_H
#define SEQUENCE_FINDER_H

#include <vector>

using namespace std;

// Utility function to count consecutive different elements
int countConsecutiveDifferent(const vector<int>& arr);

// Brute force approach to find maximum consecutive unique sequence
vector<int> bruteForceMaxConsecutive(vector<int>& numbers);

#endif