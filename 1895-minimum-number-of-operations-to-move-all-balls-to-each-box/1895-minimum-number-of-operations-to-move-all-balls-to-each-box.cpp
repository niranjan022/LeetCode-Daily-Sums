#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
class Solution {
public:
    vector<int> minOperations(string boxes) {
        fast_io;
        int n = boxes.length();  
        if(n==1)return {0} ; 
        vector<int>suffix(n,0) ; 
        vector<int>prefix(n,0) ; 
        int cnt=0; 
        int temp=0 ;
        for(int i=n-1; i>=0; i--){
            temp+=cnt ; 
            suffix[i]=temp ; 
            if(boxes[i]=='1')cnt++ ;
            cout<<suffix[i]<<" ";
        }
        cnt=0; 
        temp=0; 
        for(int i=0; i<n; i++){
            temp+=cnt; 
            prefix[i]=temp ; 
            if(boxes[i]=='1')cnt++ ; 
        }
        vector<int>ans(n); 
        for(int i=0; i<n; i++){
            if(i==0)ans[i]=suffix[i] ;
            else if(i==n-1)ans[i]=prefix[i] ; 
            else{
                ans[i]=prefix[i]+suffix[i]; 
            } 
        }
        return ans; 
    }
};