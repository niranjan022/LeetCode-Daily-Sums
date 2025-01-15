class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n1=__builtin_popcount(num1);
        int n2=__builtin_popcount(num2);
        int nc=num1;
        for(int i=31;i>=0;i--){
            if(n2>0){
                if(nc&(1<<i)){
                    nc=nc^(1<<i);
                    n2--;
                }
            }
            else break;
        }
        if(n2!=0){
        for(int i=0;i<32;i++){
            if(n2>0)
            {
                if(!(num1&(1<<i))){
                    nc=(nc^(1<<i));
                    n2--;
                }
            }
            else break;    
        }
        }
        return nc^num1;

    }
};