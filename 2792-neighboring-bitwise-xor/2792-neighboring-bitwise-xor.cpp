class Solution {
public:
    bool doesValidArrayExist(vector<int>& der) {
        int n =der.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans^der[i];
        }
        return (ans==0);
    }
};