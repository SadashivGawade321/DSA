class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0;
        int maxFreq = 0;
        int result = 0;

        vector<int> freq(256, 0);

        for (int high = 0; high < s.size(); high++) {

            freq[s[high] - 'A']++;

            maxFreq = max(maxFreq, freq[s[high] - 'A']);

            while ((high - low + 1) - maxFreq > k) {
                freq[s[low] - 'A']--;
                low++;
            }

            result = max(result, high - low + 1);
        }

        return result;
    }
};