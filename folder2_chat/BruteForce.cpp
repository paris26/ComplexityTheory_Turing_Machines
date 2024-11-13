#include "BruteForce.h"
#include <algorithm>
#include <set>

std::vector<int> longestUniqueSequenceBruteForce(std::vector<int> numbers) {
    std::vector<int> bestPermutation = numbers;
    size_t maxLength = 0;

    // Sort numbers to use next_permutation
    std::sort(numbers.begin(), numbers.end());

    do {
        // Find the length of the longest sequence of unique consecutive numbers
        std::set<int> seen;
        size_t currentLength = 0;

        for (int num : numbers) {
            if (seen.find(num) == seen.end()) {
                seen.insert(num);
                currentLength++;
            } else {
                break; // Sequence of unique numbers ended
            }
        }

        // Update the best permutation if current is longer
        if (currentLength > maxLength) {
            maxLength = currentLength;
            bestPermutation = numbers;

            // Early exit if we found the maximum possible length
            if (maxLength == numbers.size()) {
                break;
            }
        }

    } while (std::next_permutation(numbers.begin(), numbers.end()));

    return bestPermutation;
}
