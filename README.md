Here's the README in pure markdown format that you can directly paste into GitHub:

```markdown
# Maximum Consecutive Unique Sequence Algorithms

## Overview

This repository contains implementations of different algorithms for finding the longest sequence of numbers without adjacent duplicates from a given input array. The project compares three different approaches: Brute Force, Optimized Solution, and Optimal (Merge-based) Solution.

## Problem Description

Given an array of integers, find the longest possible sequence where no two adjacent numbers are the same. The algorithms handle various cases including:
- Sequences with single or multiple duplicates
- Already unique sequences
- Empty sequences
- Sequences with patterns
- Large random sequences

## Project Structure

```plaintext
├── BruteForceSequence.h/.cpp   # Brute force implementation
├── OptimizedSequence.h/.cpp    # Optimized solution using spacing technique
├── OptimalSequence.h/.cpp      # Optimal solution using merge-based approach
├── UniqueNumbers.h/.cpp        # Utility for unique number analysis
├── helper.h                    # Helper functions
└── main.cpp                    # Main program with test cases
```

## Algorithms

### 1. Unique Numbers Algorithm
- **Function**: `findUniqueNumbers`
- **Complexity**:
  - Time: O(n log n)
  - Space: O(n)
- **Purpose**: Identifies and counts unique numbers in the sequence

### 2. Optimized Sequence Algorithm
- **Function**: `findMaxConsecutiveUnique`
- **Complexity**:
  - Time: O(n²)
  - Space: O(n)
- **Approach**:
  - Creates spaced array with unique elements
  - Collects and sorts duplicates
  - Places duplicates strategically
  - Removes spacing to create final result

### 3. Brute Force Algorithm
- **Function**: `BruteForce`
- **Complexity**:
  - Time: O(n · n!)
  - Space: O(n)
- **Note**: Only suitable for small inputs (n ≤ 10) due to factorial complexity

### 4. Optimal (Merge-based) Algorithm
- **Function**: `findOptimalSequence`
- **Approach**:
  - Uses frequency counting
  - Two-sequence building strategy
  - Optimal merging technique
  - Handles duplicates efficiently

## Usage

```cpp
// Example usage
vector<int> numbers = {1, 2, 3, 3, 4, 4, 5};

// Get unique numbers analysis
UniqueNumbersResult uniqueResult = findUniqueNumbers(numbers);

// Find longest sequence without adjacent duplicates
vector<int> optimizedResult = findMaxConsecutiveUnique(numbers);
vector<int> optimalResult = findOptimalSequence(numbers);

// For small inputs only
vector<int> bruteForceResult = BruteForce(numbers);
```

## Test Cases

The project includes comprehensive test cases:
1. Simple sequence with one duplicate: `{1, 2, 3, 7, 15, 15, 18}`
2. Multiple duplicates: `{1, 1, 2, 2, 3, 3, 4, 4}`
3. Already unique sequence: `{1, 3, 5, 7, 9}`
4. Larger sequence with pattern
5. Empty sequence
6. Single element
7. All same elements
8. Random sequence with duplicates
9. Large random sequence

## Performance Metrics

The program outputs:
- Execution time (microseconds)
- Sequence length
- Resulting sequence
- Input analysis (unique numbers count)

## Building and Running

```bash
# Compile
g++ -std=c++11 *.cpp -o sequence_finder

# Run
./sequence_finder
```

## Requirements

- C++11 or higher
- Standard Template Library (STL)

## Helper Functions

- `countValidSequence`: Validates and counts sequence length
- `printArray`: Utility for array output
- `printResults`: Formatted result output
- `generateRandomSequence`: Random test case generator

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

This project is open source and available under the MIT License.
```

You can now copy this entire block and paste it directly into your GitHub repository's README.md file. GitHub will automatically render it with proper formatting.
