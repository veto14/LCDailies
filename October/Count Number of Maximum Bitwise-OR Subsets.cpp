#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0, count = 0;
        
        // Calculate the maximum bitwise OR of the entire array
        for (int num : nums) {
            maxOr |= num;
        }
        
        // Start the backtracking process from index 0
        dfs(0, 0, nums, maxOr, count);
        
        return count;
    }
    
    // Helper function to find all subsets using backtracking
    void dfs(int i, int currentOr, vector<int>& nums, int maxOr, int& count) {
        if (i == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }
        
        // Include the current element in the subset
        dfs(i + 1, currentOr | nums[i], nums, maxOr, count);
        
        // Exclude the current element from the subset
        dfs(i + 1, currentOr, nums, maxOr, count);
    }
};

