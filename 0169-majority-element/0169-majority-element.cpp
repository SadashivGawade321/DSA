class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (b == 0) {
                a = nums[i];
            }
            if (nums[i] == a) {
                b++;
            } else {
                b--;
            }
        }
        return a;
    }
    };