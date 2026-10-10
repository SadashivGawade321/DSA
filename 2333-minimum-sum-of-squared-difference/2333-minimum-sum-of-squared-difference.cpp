
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        int mx = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            sum += diff[i];
        }

        if (sum <= k) return 0;

        int left = 0, right = mx;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long operations = 0;

            for (int d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        long long ans = 0;
        long long remaining = k;

        for (int d : diff) {
            if (d > left) {
                remaining -= d - left;
                d = left;
            }
            ans += 1LL * d * d;
        }

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] >= left && diff[i] > 0) {
                ans -= 2LL * left - 1;
                remaining--;
            }
        }

        return ans;
    }
};
