#include "sequence_finder.h"
#include <algorithm>

int countConsecutiveDifferent(const vector<int>& arr) {
    if (arr.empty()) return 0;
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i-1]) return 0;
    }
    return arr.size();
}

vector<int> bruteForceMaxConsecutive(vector<int>& numbers) {
    vector<int> bestArrangement = numbers;
    int maxLength = countConsecutiveDifferent(numbers);

    sort(numbers.begin(), numbers.end());
    do {
        int currentLength = countConsecutiveDifferent(numbers);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            bestArrangement = numbers;
        }
    } while(next_permutation(numbers.begin(), numbers.end()));

    return bestArrangement;
}