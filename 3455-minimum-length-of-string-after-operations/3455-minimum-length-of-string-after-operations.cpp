class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        int size=0;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                if(freq[i]&1) size++;
                else size+=2;
            }
        }
        return size;
    }
};