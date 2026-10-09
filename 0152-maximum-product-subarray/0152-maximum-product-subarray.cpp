class Solution {
public:
    int maxProduct(vector<int>& n) {
        int minend = n[0];
        int maxend = n[0];
        int ans = n[0];
        for (int i = 1; i < n.size(); i++) {
            int v1 = minend * n[i];
            int v2 = n[i];
            int v3 = maxend * n[i];
            maxend = max(v2,max(v1,v3));
            minend = min(v2,min(v1,v3));
            
            ans = max(ans, max(maxend,minend));
        }

        return ans;
    }
};