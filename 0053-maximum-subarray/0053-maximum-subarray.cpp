class Solution {
public:
    int maxSubArray(vector<int>& n) {
    int bestend = n[0];
    int ans = n[0];
     for(int i = 1; i<n.size();i++){
        int v1 = bestend + n[i];
        int v2 = n[i];
        bestend = max(v1,v2);
        ans = max(ans,bestend);
     }


      return ans;






    }
};