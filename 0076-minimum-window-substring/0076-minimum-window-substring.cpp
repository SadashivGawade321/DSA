class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        if (m > n)
            return "";

        vector<int> need(256, 0);
        vector<int> have(256, 0);

        // Store frequency of characters required from t
        for (char ch : t) {
            need[ch]++;
        }

        int low = 0;
        int high = 0;

        int count = 0;          // characters matched
        int minLen = INT_MAX;
        int start = -1;

        while (high < n) {

            // Add s[high] to current window
            have[s[high]]++;

            // If this character is still needed
            if (have[s[high]] <= need[s[high]]) {
                count++;
            }

            // Window is valid
            while (count == m) {

                int len = high - low + 1;

                // Update minimum window
                if (len < minLen) {
                    minLen = len;
                    start = low;
                }

                // Remove s[low]
                if (have[s[low]] <= need[s[low]]) {
                    count--;
                }

                have[s[low]]--;
                low++;
            }

            high++;
        }

        if (start == -1)
            return "";

        return s.substr(start, minLen);
    }
};