#ifndef UNIQUE_NUMBERS_H
#define UNIQUE_NUMBERS_H

#include <vector>
#include <utility>  

using namespace std;

// we declare a struct for easier use
struct UniqueNumbersResult {
    vector<int> uniqueNumbers;
    int count;
};

UniqueNumbersResult findUniqueNumbers(const vector<int>& numbers);

void printUniqueNumbers(const vector<int>& numbers);

#endif