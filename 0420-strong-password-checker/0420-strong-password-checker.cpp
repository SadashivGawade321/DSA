
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();

        bool lower = false, upper = false, digit = false;

        for (char c : password) {
            if (c >= 'a' && c <= 'z') lower = true;
            if (c >= 'A' && c <= 'Z') upper = true;
            if (c >= '0' && c <= '9') digit = true;
        }

        int missing = !lower + !upper + !digit;

        int replace = 0;
        vector<int> runs;

        // Find consecutive repeating character groups
        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && password[j] == password[i]) {
                j++;
            }

            int len = j - i;

            if (len >= 3) {
                replace += len / 3;
                runs.push_back(len);
            }

            i = j;
        }

        // Case 1: Length is less than 6
        if (n < 6) {
            return max(missing, 6 - n);
        }

        // Case 2: Length is between 6 and 20
        if (n <= 20) {
            return max(missing, replace);
        }

        // Case 3: Length is greater than 20
        int deletions = n - 20;
        int remaining = deletions;

        // Priority 1: Runs where len % 3 == 0
        for (int &len : runs) {
            if (remaining > 0 && len % 3 == 0) {
                len--;
                remaining--;
                replace--;
            }
        }

        // Priority 2: Runs where len % 3 == 1
        for (int &len : runs) {
            if (remaining >= 2 && len % 3 == 1) {
                len -= 2;
                remaining -= 2;
                replace--;
            }
        }

        // Priority 3: Every 3 deletions reduce one replacement
        replace -= min(replace, remaining / 3);

        return deletions + max(missing, replace);
    }
};
