class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(words[i].size()<=words[j].size()){
                    string s1 = words[j].substr(0,words[i].size());
                    string s2 = words[j].substr(words[j].size()-words[i].size(),words[i].size());
                    int a1 = s1.find(words[i]);
                    int a2= s2.find(words[i]);
                    if(a1!=-1 and a2!=-1) cnt++;
                }
            }
        }
        return cnt;
    }
};