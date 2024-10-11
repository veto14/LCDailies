#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> matrix(m, vector<int>(n, -1));  // Initialize matrix with -1
    
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    
    ListNode* current = head;
    
    // Fill the matrix in spiral order
    while (top <= bottom && left <= right && current != nullptr) {
        // Traverse from left to right on the top row
        for (int i = left; i <= right && current != nullptr; ++i) {
            matrix[top][i] = current->val;
            current = current->next;
        }
        ++top;  // Move the top boundary down
        
        // Traverse from top to bottom on the right column
        for (int i = top; i <= bottom && current != nullptr; ++i) {
            matrix[i][right] = current->val;
            current = current->next;
        }
        --right;  // Move the right boundary left
        
        // Traverse from right to left on the bottom row
        for (int i = right; i >= left && current != nullptr; --i) {
            matrix[bottom][i] = current->val;
            current = current->next;
        }
        --bottom;  // Move the bottom boundary up
        
        // Traverse from bottom to top on the left column
        for (int i = bottom; i >= top && current != nullptr; --i) {
            matrix[i][left] = current->val;
            current = current->next;
        }
        ++left;  // Move the left boundary right
    }
    
    return matrix;
}
