
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        int maxEnd = 0, maxSum = INT_MIN;
        int minEnd = 0, minSum = INT_MAX;

        for (int i = 0; i < n; i++) {
            maxEnd = max(nums[i], maxEnd + nums[i]);
            maxSum = max(maxSum, maxEnd);

            minEnd = min(nums[i], minEnd + nums[i]);
            minSum = min(minSum, minEnd);

            total += nums[i];
        }

        if (maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, total - minSum);
    }
};
