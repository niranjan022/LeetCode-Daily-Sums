class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int minind = INT_MAX;
        vector<int> st(arr.size());
        for(int i=0;i<arr.size();i++){
            st[arr[i]-1]=i;
        }
        for(int i=0;i<mat.size();i++){
            int a = -1;
            for(int j=0;j<mat[i].size();j++){
                a = max(a,st[mat[i][j]-1]);
            }
            minind = min(minind,a);
        }

        for(int i=0;i<mat[0].size();i++){
            int a = 0;
            for(int j=0;j<mat.size();j++){
                a = max(a,st[mat[j][i]-1]);
            }
            minind = min(minind,a);
        }
        return minind;
    }
};