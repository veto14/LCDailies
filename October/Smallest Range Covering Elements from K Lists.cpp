#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap to store (value, list index, element index within the list)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        
        int maxVal = INT_MIN; // Track the largest value in the current window
        int rangeStart = 0, rangeEnd = INT_MAX;
        
        // Step 1: Initialize the heap with the first element of each list
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]); // Track the maximum element in the initial window
        }
        
        // Step 2: Process the heap until we run out of elements in one list
        while (minHeap.size() == nums.size()) {
            auto [minVal, idxPair] = minHeap.top(); minHeap.pop();
            int listIdx = idxPair.first, elemIdx = idxPair.second;
            
            // Update the smallest range if the current range is smaller
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }
            
            // Step 3: If possible, add the next element of the list to the heap
            if (elemIdx + 1 < nums[listIdx].size()) {
                int nextVal = nums[listIdx][elemIdx + 1];
                minHeap.push({nextVal, {listIdx, elemIdx + 1}});
                maxVal = max(maxVal, nextVal); // Update the maximum value in the window
            }
        }
        
        return {rangeStart, rangeEnd}; // Return the smallest range
    }
};
