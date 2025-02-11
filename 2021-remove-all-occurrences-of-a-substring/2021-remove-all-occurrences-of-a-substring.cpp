class Solution {
public:
    string removeOccurrences(string s, string part) {
        int f=s.find(part);
        int siz = part.size();
        while(f!=-1){
            s.erase(f,siz);
            f=s.find(part);
        }
        return s;
    }
};