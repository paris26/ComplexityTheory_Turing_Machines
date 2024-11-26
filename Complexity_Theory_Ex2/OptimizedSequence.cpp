#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> findMaxConsecutiveUnique(const vector<int>& numbers) {
    if (numbers.empty()) return {};
    
    // Step 1: Create spaced array and collect duplicates
    vector<int> spacedArray;
    vector<int> duplicates;
    unordered_set<int> seen;
    
    // Note: First pass - create spaced array with unique elements
    for (int num : numbers) {
        // Note: if you do not find it and reach the end 
        //        include it in the space array && check as seen
        if (seen.find(num) == seen.end()) {
            spacedArray.push_back(num);
            spacedArray.push_back(-1);  // Using -1 as spacer || instead of _ or #
            seen.insert(num);
        } else {
            duplicates.push_back(num);
        }
    }
    
    // Step 2: Sort duplicates in descending order
    /* 
        Note: we sort them in descending order to arrange them backwards 
              e.g. [1,2,3] & [1,3] -> 
     */
    sort(duplicates.begin(), duplicates.end(), greater<int>());
    
    // Step 3: Try to place duplicates
    /* 
        For every duplicate 
        we set a flag 
        check left & right
        if no complaint push it 
        else move to next space (-1)
    */
    for (int dup : duplicates) {
        bool placed = false;
        for (int i = spacedArray.size() - 1; i >= 0; i--) {
            if (spacedArray[i] == -1) {  // Found a space
                // Check adjacent elements
                bool leftOk = (i == 0 || spacedArray[i-1] != dup);
                bool rightOk = (i == spacedArray.size()-1 || spacedArray[i+1] != dup);
                
                if (leftOk && rightOk) {
                    spacedArray[i] = dup;
                    placed = true;
                    break;
                }
            }
        }
        if (!placed) break;  // If we couldn't place this duplicate, no more space so break 
    }
    
    // Step 4: Create final array without spaces
    vector<int> result;
    for (int num : spacedArray) {
        if (num != -1) {
            result.push_back(num);
        }
    }
    
    return result;
}