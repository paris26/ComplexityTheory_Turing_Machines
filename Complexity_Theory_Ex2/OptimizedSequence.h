#ifndef OPTIMIZED_SEQUENCE_H
#define OPTIMIZED_SEQUENCE_H

#include <vector>

using namespace std;

struct MergeResult {
    vector<int> primary;
    vector<int> duplicates;
};

vector<int> findMaxConsecutiveUnique(const vector<int>& numbers);

#endif