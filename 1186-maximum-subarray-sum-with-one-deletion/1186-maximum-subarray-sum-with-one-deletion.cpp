
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete = arr[0];
        int onedelete = 0;
        int ans = arr[0];
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            onedelete = max(nodelete, onedelete + arr[i]);
            nodelete = max(nodelete + arr[i], arr[i]);

            ans = max(ans, max(nodelete, onedelete));
        }

        return ans;
    }
};
