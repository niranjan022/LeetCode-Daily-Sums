class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int s =nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                s+=nums[i];
            }
            else{
                ans=max(ans,s);
                s=nums[i];
            }
        }
        ans = max(ans,s);
        return ans;
    }
};