class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size())
            return "";

        unordered_map<char, int> mp;

        // Frequency required from t
        for (char ch : t) {
            mp[ch]++;
        }

        int low = 0;
        int high = 0;

        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;

        while (high < s.size()) {

            // Character enters the window
            if (mp[s[high]] > 0) {
                count--;
            }

            mp[s[high]]--;
            high++;

            // Window contains all characters
            while (count == 0) {

                // Update minimum window
                if (high - low < minLen) {
                    minLen = high - low;
                    start = low;
                }

                // Remove left character
                mp[s[low]]++;

                if (mp[s[low]] > 0) {
                    count++;
                }

                low++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};