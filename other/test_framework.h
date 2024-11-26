#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <vector>
#include <string>

using namespace std;

class TestFramework {
private:
    static const int BRUTE_FORCE_THRESHOLD = 10;
    
    // Helper functions
    static int countMaxConsecutiveDifferent(const vector<int>& arr);
    static void printArray(const vector<int>& arr, const string& message);

    struct TestResult {
        vector<int> solution;
        long long timeTaken;
        int maxConsecutive;
        TestResult(vector<int> sol, long long time);
    };

    static void compareResults(const vector<TestResult>& results, 
                             const vector<string>& methodNames);

    // Parameters for random sequence generation
    struct GenerationParams {
        int sequenceLength;      // Length of sequence
        int minValue;           // Minimum value in sequence
        int maxValue;           // Maximum value in sequence
        int maxDuplicates;      // Maximum times a number can appear
    };

    static vector<int> generateRandomSequence(const GenerationParams& params);

public:
    static void runTestSuite();
    static void testSequence(const vector<int>& numbers, const string& testName);
};

#endif