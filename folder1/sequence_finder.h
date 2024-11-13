#ifndef SEQUENCE_FINDER_H
#define SEQUENCE_FINDER_H

#include <vector>

using namespace std;

class SequenceFinder {
    public:
        static int countConsecutiveDifferent(const vector<int>& arr);

        static vector<int> bruteForceMaxConsecutive( vector <int>& numbers);

        static vector<int> optimizedMaxConsecutive(const vector<int>& numbers);

        static void runPartB(const vector<int>& numbers);
};


#endif 