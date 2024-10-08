#include <stack>
#include <string>

using namespace std;

int minLength(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (!st.empty()) {
            // Check if the top of the stack forms "AB" or "CD" with the current character
            if ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D')) {
                st.pop();  // Remove the matching pair
            } else {
                st.push(c);  // Otherwise, push the current character onto the stack
            }
        } else {
            st.push(c);  // Push the character if stack is empty
        }
    }
    
    // The size of the stack represents the minimum possible length
    return st.size();
}
