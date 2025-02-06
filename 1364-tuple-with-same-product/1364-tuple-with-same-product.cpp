class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // vector<long long> f;
        unordered_map<long long,int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long a = nums[i]*nums[j];
                st[a]++;
            }
        }
        int cnt=0;
        for(auto m:st){
            if(m.second>1){
                cnt +=(m.second*2*(m.second*2-2));
            }
        }
        return cnt;
    }
};