class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());

        int n = nums1.size();

        // Smallest element cannot be changed.
        int target = nums1[0] % 2;

        for (int i = 1; i < n; i++) {

            // Already has the required parity
            if (nums1[i] % 2 == target)
                continue;

            // Need to subtract a smaller number
            // having even parity to keep/change accordingly.
            bool possible = false;

            for (int j = 0; j < i; j++) {
                if ((nums1[i] - nums1[j]) >= 1 &&
                    (nums1[i] - nums1[j]) % 2 == target) {
                    possible = true;
                    break;
                }
            }

            if (!possible)
                return false;
        }

        return true;
    }
};