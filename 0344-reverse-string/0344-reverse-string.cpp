class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;

        for (char ch : s) {
            st.push(ch);
        }

        // Put characters back
        for (int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }
    }
};