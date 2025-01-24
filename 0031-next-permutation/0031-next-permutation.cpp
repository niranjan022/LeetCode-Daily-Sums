class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot  = i;
                break;
            }
        }
        if(pivot<0){
            sort(nums.begin(),nums.end());
        }
        else{
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[pivot]){
                int t=nums[pivot];
                nums[pivot] = nums[i];
                nums[i]=t;
                sort(nums.begin()+pivot+1,nums.end());
                break;
            }
        }
        }

    }
};