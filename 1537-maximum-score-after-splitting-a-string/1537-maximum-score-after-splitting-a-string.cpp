#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
class Solution {
public:
    int maxScore(string s) {
        fast_io;
        int t = 0;
        for(int i=0;i<s.size()-1;i++){
            string st=s.substr(0,i+1);
            string st1=s.substr(i+1);
            int z = count(st.begin(),st.end(),'0');
            int o = count(st1.begin(),st1.end(),'1');
            t=max(z+o,t);
        }
        return t;
    }
};
