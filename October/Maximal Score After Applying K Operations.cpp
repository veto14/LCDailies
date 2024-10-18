#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Max-heap to always pick the largest element
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        long long score = 0; // To store the maximum score
        
        // Perform k operations
        for (int i = 0; i < k; ++i) {
            int top = maxHeap.top(); // Get the largest element
            maxHeap.pop(); // Remove it from the heap
            score += top; // Add it to the score
            
            // Replace it with ceil(top / 3) and push back into the heap
            int newValue = (top + 2) / 3; // Ceil(top / 3)
            maxHeap.push(newValue);
        }
        
        return score;
    }
};
