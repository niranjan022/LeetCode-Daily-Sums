class Solution {
public:
    vector<string> stringMatching(vector<string>& w) {
        vector<string> ans;
        for(int i=0;i<w.size();i++){
            for(int j=0;j<w.size();j++){
                if(i!=j and w[j].size()>=w[i].size()){
                    if(w[j].find(w[i])!=string::npos){
                            ans.push_back(w[i]);
                            break;
                    }                    
                }
            }
        }
        return ans;
    }
};