class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(int i=0;i<words.size();i++)
        {
            string s =words[i].substr(0,pref.size());
            if(s==pref) cnt++;
        }
        return cnt;
    }
};