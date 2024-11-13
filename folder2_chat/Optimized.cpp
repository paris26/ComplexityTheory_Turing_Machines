#include "Optimized.h"
#include <unordered_map>
#include <algorithm>

std::vector<int> longestUniqueSequenceOptimized(const std::vector<int>& numbers) {
    std::unordered_map<int, int> frequency;

    // Count frequency of each number
    for (int num : numbers) {
        frequency[num]++;
    }

    // Extract unique numbers
    std::vector<int> uniqueNumbers;
    for (const auto& pair : frequency) {
        uniqueNumbers.push_back(pair.first);
    }

    // Sort unique numbers (optional, for consistent ordering)
    std::sort(uniqueNumbers.begin(), uniqueNumbers.end());

    // Prepare the result vector
    std::vector<int> result = uniqueNumbers;

    // Append duplicates
    for (const auto& pair : frequency) {
        int count = pair.second;
        for (int i = 1; i < count; ++i) {
            result.push_back(pair.first);
        }
    }

    return result;
}
