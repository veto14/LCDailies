#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Priority queue to store the remaining counts of 'a', 'b', and 'c'.
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";
        
        // Previous two characters used (count and char)
        pair<int, char> prev1 = {0, '#'}, prev2 = {0, '#'};
        
        while (!pq.empty()) {
            auto [count, ch] = pq.top(); pq.pop();
            
            // Append the character if it doesn't form an invalid sequence
            if (result.size() >= 2 && result.back() == ch && result[result.size()-2] == ch) {
                if (pq.empty()) break;
                
                auto [count2, ch2] = pq.top(); pq.pop();
                result += ch2;
                count2--;
                
                if (count2 > 0) pq.push({count2, ch2});
                pq.push({count, ch});
            } else {
                result += ch;
                count--;
                
                if (count > 0) pq.push({count, ch});
            }
        }

        return result;
    }
};
