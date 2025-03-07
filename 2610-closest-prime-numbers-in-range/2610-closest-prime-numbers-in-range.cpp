class Solution {
public:
    bool check(int n){
        if(n<=1) return false;
        int cnt = 0;
        
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                cnt++;
            }
            if(cnt>0) return false; 
        }
        return true; 
    }
    vector<int> closestPrimes(int left, int right) {
        int num1 = -1,num2=-1;
        vector<int> v; 
        for(int i=left;i<=right;i++){
            if(check(i)) v.push_back(i);
        }
        int small = INT_MAX;
        if(v.size()<2) return {-1,-1};
        for(int i=v.size()-1;i>0;i--){
            int diff = v[i] - v[i-1];
            if(small>=diff){
                num1 = v[i-1],num2 = v[i];
                small = diff;
            }
            // else if(small == diff){
            //     if(num1>v[i]){
            //         num1 = v[i];
            //         num2 = v[i+1];
            //     }
            // }
        }
        return {num1,num2};
    }
};