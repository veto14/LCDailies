#include <stdbool.h>

bool canArrange(int* arr, int arrSize, int k) {
    int remainderCount[k];  // To store frequency of remainders
    for (int i = 0; i < k; i++) {
        remainderCount[i] = 0;
    }

    // Count the remainder frequencies
    for (int i = 0; i < arrSize; i++) {
        int rem = ((arr[i] % k) + k) % k;  // Handle negative numbers
        remainderCount[rem]++;
    }

    // Check for valid pairs
    for (int i = 1; i < k; i++) {
        if (remainderCount[i] != remainderCount[k - i]) {
            return false;
        }
    }

    // Special case: For remainder 0, there must be an even count
    if (remainderCount[0] % 2 != 0) {
        return false;
    }

    return true;
}
