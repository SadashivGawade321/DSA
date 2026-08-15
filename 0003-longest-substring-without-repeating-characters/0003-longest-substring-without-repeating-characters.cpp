class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int low = 0;
        int high = 0;
        int maxLen = 0;
        unordered_map<char, int> mp;

        while (high < s.size()) {
            mp[s[high]]++;

            while (mp[s[high]] > 1) {
                mp[s[low]]--;
                low++;
            }
            maxLen = max(maxLen, high - low + 1);

            high++;
        }

        return maxLen;
    }
};