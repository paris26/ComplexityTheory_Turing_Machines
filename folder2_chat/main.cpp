#include <iostream>
#include <vector>
#include "PartA.h"
#include "BruteForce.h"
#include "Optimized.h"

int main() {
    int n;

    std::cout << "Enter the number of elements (n): ";
    std::cin >> n;

    std::vector<int> numbers(n);

    std::cout << "Enter " << n << " integers:\n";
    for (int& num : numbers) {
        std::cin >> num;
    }

    // Part A
    std::vector<int> uniqueNumbers = findUniqueNumbers(numbers);
    std::cout << "\nNumbers that appear exactly once:\n";
    for (int num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << "\nTotal unique numbers: " << uniqueNumbers.size() << "\n";

    // Part B - Brute Force
    std::vector<int> bestPermutationBruteForce = longestUniqueSequenceBruteForce(numbers);
    std::cout << "\nBest permutation (Brute Force):\n";
    for (int num : bestPermutationBruteForce) {
        std::cout << num << " ";
    }
    std::cout << "\nLongest unique sequence length: " << uniqueNumbers.size() << "\n";

    // Part B - Optimized
    std::vector<int> bestPermutationOptimized = longestUniqueSequenceOptimized(numbers);
    std::cout << "\nBest permutation (Optimized):\n";
    for (int num : bestPermutationOptimized) {
        std::cout << num << " ";
    }
    std::cout << "\nLongest unique sequence length: " << uniqueNumbers.size() << "\n";

    return 0;
}
