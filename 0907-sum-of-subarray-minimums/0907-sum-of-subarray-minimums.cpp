class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        int mod = 1e9 + 7;

        stack<int> st;

        vector<int> left(n), right(n);

        // Previous smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next smaller or equal element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate contribution
        for (int i = 0; i < n; i++) {
            long long count = (long long)(i - left[i]) * (right[i] - i);
            ans = (ans + arr[i] * count) % mod;
        }

        return ans;
    }
};