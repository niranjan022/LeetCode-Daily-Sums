class Solution {
public:
    string clearDigits(string s) {
        string st="";
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                st.pop_back();
            }
            else st.push_back(s[i]);
        }
       return st;
    }
};