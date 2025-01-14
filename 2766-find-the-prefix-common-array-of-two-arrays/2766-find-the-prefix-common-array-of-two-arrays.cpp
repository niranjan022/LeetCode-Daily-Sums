class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> left(A.size(),0),rig(B.size(),0);
        vector<int> ans(A.size(),0);
        left[A[0]-1]=1;
        rig[B[0]-1]=1;
        if(A[0]==B[0]){
            ans[0]=1;
        }
        else ans[0]=0;
        for(int i=1;i<A.size();i++){
            left[A[i]-1]=1;
            rig[B[i]-1]=1;
            if(A[i]==B[i]) ans[i]=ans[i-1]+1;
            else if(left[B[i]-1] and rig[A[i]-1]) ans[i] = ans[i-1]+2;
            else if (left[B[i]-1] or rig[A[i]-1]) ans[i] = ans[i-1]+1;
            else ans[i]=ans[i-1];
        }
        return ans;
    }
};