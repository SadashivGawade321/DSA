class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int low = 0;
      int high =0;
      int sum = 0;
      int result = INT_MAX;


      while (high<nums.size()){
        sum += nums[high];
while(sum>=target){
    int len = high -low +1;
    result = min(result,len);

    sum = sum-nums[low];
    low++;

}
high++;
      }
  if(result == INT_MAX)
  return 0;

  return result;





    }
};