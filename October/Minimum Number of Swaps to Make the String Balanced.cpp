#include <string>

using namespace std;

int minSwaps(string s) {
    int imbalance = 0;  // Tracks how many unpaired ']' we have
    int swaps = 0;      // Number of swaps required to balance the string

    for (char c : s) {
        if (c == '[') {
            imbalance--;  // Every '[' can balance one ']', so decrease imbalance
        } else {
            imbalance++;  // Every ']' increases imbalance unless it's already balanced
        }

        // If imbalance becomes positive, we need a swap to fix the unbalanced ']'
        if (imbalance > 0) {
            swaps++;        // Swap to balance this ']' with a future '['
            imbalance -= 2; // One swap fixes two brackets, so reduce imbalance by 2
        }
    }

    return swaps;
}
