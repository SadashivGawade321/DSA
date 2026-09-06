class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();

        vector<vector<long long>> dp(n + 1,
                                     vector<long long>(m + 1, -1));

        function<long long(int, int)> solve = [&](int i, int j) {
            
            // t is completely formed
            if (j == m)
                return 1LL;

            // s is finished but t is not
            if (i == n)
                return 0LL;

            // Already calculated
            if (dp[i][j] != -1)
                return dp[i][j];

            if (s[i] == t[j]) {
                
                // Use s[i] OR skip s[i]
                dp[i][j] = solve(i + 1, j + 1)
                         + solve(i + 1, j);
            }
            else {
                
                // Characters don't match, so skip s[i]
                dp[i][j] = solve(i + 1, j);
            }

            return dp[i][j];
        };

        return solve(0, 0);
    }
};