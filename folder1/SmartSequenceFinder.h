#ifndef SMART_SEQUENCE_FINDER_H
#define SMART_SEQUENCE_FINDER_H

#include <vector>
#include <unordered_map>
using namespace std;

class SmartSequenceFinder {
private:
    static int findLongestSequence(const vector<int>& arr);
    static vector<int> slidingWindowOptimize(vector<int>& numbers);
    static vector<int> getFrequencyBasedArrangement(const vector<int>& numbers);

public:
    static vector<int> findMaxConsecutiveUnique(const vector<int>& numbers);
    static int countConsecutiveDifferent(const vector<int>& arr);
};

#endif