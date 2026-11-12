
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        long long maxSum = 0;
        long long minSum = 0;

        stack<int> st;

        // Calculate sum of subarray minimums
        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&
                   (i == n || nums[st.top()] > nums[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                minSum += 1LL * nums[mid] *
                          (mid - left) * (right - mid);
            }

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Calculate sum of subarray maximums
        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&
                   (i == n || nums[st.top()] < nums[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                maxSum += 1LL * nums[mid] *
                          (mid - left) * (right - mid);
            }

            st.push(i);
        }

        return maxSum - minSum;
    }
};
