class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>out;
        int c=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if (nums[i]+nums[j]==target){
                    out.push_back(i);
                    out.push_back(j);
                    return out;
                }
            }
        }
        return out;
    }
};