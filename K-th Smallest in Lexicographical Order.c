#include <stdio.h>

int findKthNumber(int n, int k) {
    int curr = 1;
    k--;  // We start with 1, so decrement k

    while (k > 0) {
        long currPrefix = curr;
        long nextPrefix = curr + 1;
        int steps = 0;

        // Count how many numbers are within this subtree (same as `countSteps`)
        while (currPrefix <= n) {
            steps += (nextPrefix <= n ? nextPrefix - currPrefix : n - currPrefix + 1);
            currPrefix *= 10;
            nextPrefix *= 10;
        }

        // If steps is less than or equal to k, move to the next sibling
        if (steps <= k) {
            k -= steps;
            curr++;
        } else {
            // Move down to the next level in the tree (deeper subtree)
            curr *= 10;
            k--;
        }
    }

    return curr;
}