class Solution {
public:
    int totalFruit(vector<int>& f) {

        int low = 0;
        int high = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;
        while (high < f.size()) {
            mp[f[high]]++;
            while (mp.size() > 2) {
                mp[f[low]]--;
                if (mp[f[low]] == 0) {
                    mp.erase(f[low]);
                }
                low++;
            }

            maxLen = max(maxLen, high - low + 1);

            high++;
        }
        return maxLen;
    }
};