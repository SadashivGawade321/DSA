class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
    vector<int> a;
 
    vector<int> b;
  for (int i=0;i<n;i++){
    if(nums[i]<0){
        a.push_back(nums[i]);
        }
        else{
        b.push_back(nums[i]);
    }
  }
   for (int i=0 ;i<a.size();i++){
       a[i] = a[i] * a[i];
   }
      for (int i=0 ;i<b.size();i++){
       b[i] = b[i] * b[i];
   }

   reverse(a.begin() , a.end());

     vector<int> res;
          int i =0;
         int  j= 0;
       
         while (i<a.size() && j<b.size()){
            if (a[i]<=b[j]){
                res.push_back(a[i]);
                i++;
            }
            else {
           res.push_back(b[j]);
                
                j++;
            }
            
         }

         while (i < a.size()) {
           res.push_back(a[i]);
            i++;
          
        }

        while (j < b.size()) {
            res.push_back(b[j]);
            j++;
           
        }

        return res;
    }
};






        
    