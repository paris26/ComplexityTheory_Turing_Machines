#ifndef HELPER_H
#define HELPER_H

#include <vector>

using namespace std;

    int countValidSequence(const vector<int>& arr) {
        if (arr.empty()) return 0;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                return 0;
            }
        }

        return arr.size();
    }

#endif