class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxend = 0;
        int minend = 0;
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            maxend = max(0, maxend + nums[i]);
            minend = min(0, minend + nums[i]);
            ans = max(ans, abs(maxend));
            ans = max(ans, abs(minend));
        }
        return ans;
    }
};