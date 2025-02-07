class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        unordered_map<int,int> mp,mp1;
        int n = q.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
           if(mp.count(q[i][0])){
                int a = mp[q[i][0]];
                mp1[a]--;
                if(mp1[a]==0) mp1.erase(a);
                mp[q[i][0]]=q[i][1];
                mp1[q[i][1]]++;
           }
           else{
            mp[q[i][0]] = q[i][1];
            mp1[q[i][1]]++;
           }
           int s1 = mp.size(),s2=mp1.size();
           ans[i] = min(s1,s2);
        }
        return ans;
    }
};