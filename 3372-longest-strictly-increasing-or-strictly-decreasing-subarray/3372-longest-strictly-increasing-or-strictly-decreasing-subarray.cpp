class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1;
        int prev = 0,prev1=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                inc = max(inc,i-prev+1);
            }
            else{
                prev = i;
            }
             if(nums[i-1]>nums[i]){
                dec=max(dec,i-prev1+1);
            }
            else{
                prev1 = i;
            }
        }
        return max(dec,inc);
    }
};