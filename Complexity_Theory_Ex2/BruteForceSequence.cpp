#include <vector>
#include <algorithm>

using namespace std;

// Helper function to check if a sequence has no adjacent duplicates
bool isValidSequence(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i-1]) {
            return false;
        }
    }
    return true;
}

vector<int> BruteForce(vector<int>& numbers) {
    vector<int> bestSequence;
    int maxLength = 0;
    
    // Sort the input array
    sort(numbers.begin(), numbers.end());
    
    do {
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i; j < numbers.size(); j++) {
                // Extract subsequence from i to j
                vector<int> currentSeq(numbers.begin() + i, numbers.begin() + j + 1);
                
                if (isValidSequence(currentSeq) && currentSeq.size() > maxLength) {
                    maxLength = currentSeq.size();
                    bestSequence = currentSeq;
                }
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    return bestSequence;
}