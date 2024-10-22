#include <iostream>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: for S1, the only bit is '0'
        if (n == 1) {
            return '0';
        }
        
        // Find the length of the string Sn, which is 2^n - 1
        int length = (1 << n) - 1;
        int mid = length / 2 + 1;  // Middle position is length/2 + 1
        
        if (k == mid) {
            // If k is the middle element, it's always '1'
            return '1';
        } else if (k < mid) {
            // If k is in the first half, it's the same as in Sn-1
            return findKthBit(n - 1, k);
        } else {
            // If k is in the second half, we find the corresponding position in the reverse and inverted part
            // Corresponding position in the first half is: (mid - (k - mid))
            char correspondingBit = findKthBit(n - 1, mid - (k - mid));
            // Invert the bit: '0' becomes '1', and '1' becomes '0'
            return correspondingBit == '0' ? '1' : '0';
        }
    }
};
