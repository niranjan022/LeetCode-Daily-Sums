class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0;
        vector<int> feq(27,0);
        for(char& ch:s2) feq[ch-'a']++;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(feq[s1[i]-'a']<1){
                    return false;
                }
                else{
                    feq[s1[i]-'a']--;
                }    
            }
            else{
                if(feq[s1[i]-'a']<1) return false;
            }    
        }
        if(cnt==0 or cnt==2) return true;
        return false;
    }
};