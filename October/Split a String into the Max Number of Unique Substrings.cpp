#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen; // Set to store the unique substrings
        return backtrack(s, 0, seen);
    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        if (start == s.length()) return 0; // Reached the end of the string

        int maxSplits = 0;
        string current;

        // Try every possible split starting from the current position
        for (int i = start; i < s.length(); ++i) {
            current += s[i]; // Build the substring
            // If the substring hasn't been seen before
            if (seen.find(current) == seen.end()) {
                seen.insert(current); // Mark the substring as seen
                maxSplits = max(maxSplits, 1 + backtrack(s, i + 1, seen)); // Recursively try to split the remaining part
                seen.erase(current); // Backtrack and remove the substring from the set
            }
        }

        return maxSplits; // Return the maximum number of splits
    }
};
