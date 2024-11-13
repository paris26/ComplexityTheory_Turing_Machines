#include "PartA.h"
#include <unordered_map>

std::vector<int> findUniqueNumbers(const std::vector<int>& numbers) {
    std::unordered_map<int, int> frequency;

    // Count the frequency of each number
    for (int num : numbers) {
        frequency[num]++;
    }

    // Collect numbers that appear exactly once
    std::vector<int> uniqueNumbers;
    for (const auto& pair : frequency) {
        if (pair.second == 1) {
            uniqueNumbers.push_back(pair.first);
        }
    }

    return uniqueNumbers;
}
