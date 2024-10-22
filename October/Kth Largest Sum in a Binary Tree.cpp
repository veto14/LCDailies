#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1; // If the root is null, return -1
        
        // Queue for BFS traversal
        queue<TreeNode*> q;
        q.push(root);
        
        // Vector to store the sums of each level
        vector<long long> levelSums;
        
        // BFS traversal to calculate level sums
        while (!q.empty()) {
            int levelSize = q.size();
            long long levelSum = 0;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val;
                
                // Push the left and right children into the queue if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Store the sum of the current level
            levelSums.push_back(levelSum);
        }
        
        // If there are fewer than k levels, return -1
        if (levelSums.size() < k) return -1;
        
        // Sort the level sums in descending order
        sort(levelSums.rbegin(), levelSums.rend());
        
        // Return the k-th largest level sum
        return levelSums[k - 1];
    }
};
