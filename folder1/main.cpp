#include "unique_numbers.h"
#include "sequence_finder.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements (n): ";
    cin >> n;
    
    vector<int> numbers(n);
    cout << "Enter " << n << " numbers:\n";
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    // Run Part A
    UniqueNumbersFinder finder;
    finder.runPartA(numbers);
    
    // Run Part B
    SequenceFinder::runPartB(numbers);
    
    return 0;
}