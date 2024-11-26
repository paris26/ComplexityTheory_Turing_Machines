#include <vector>
#include <algorithm>

using namespace std;

bool isValidSequence(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i-1]) return false;
    }
    return true;
}

vector<int> BruteForce(vector<int>& numbers) {
    if (numbers.empty()) return {};
    
    vector<int> bestSequence;
    int n = numbers.size();
    
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> currentSeq;
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                currentSeq.push_back(numbers[i]);
            }
        }
        
        if (isValidSequence(currentSeq) && currentSeq.size() > bestSequence.size()) {
            bestSequence = currentSeq;
        }
    }
    
    return bestSequence;
}