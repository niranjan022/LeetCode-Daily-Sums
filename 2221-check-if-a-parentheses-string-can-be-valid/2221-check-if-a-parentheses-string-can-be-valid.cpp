class Solution {
public:
    bool canBeValid(string s, string locked) {
        int size = s.size();
        if(size&1) return false;
        int lef=0,rig=0;
        for(int i=0;i<size;i++){
            if(locked[i]=='1'){
                if(s[i]=='('){
                    lef++;
                    rig++;
                }
                else{
                    lef--;
                    rig--;
                }
            }else{
                lef--;
                rig++;
            }
            if(lef<0) lef=0;
            if(rig<0) return false;
        }    
            return (lef==0); 
        
    }
};