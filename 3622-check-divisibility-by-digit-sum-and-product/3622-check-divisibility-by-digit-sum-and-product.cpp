class Solution {
public:
    bool checkDivisibility(int n) {
        int p=1,s=0,t=n;
        while(t>0){
            int r=t%10;
            p*=r;
            s+=r;
            t/=10;
        }
        if(n%(s+p)==0)return true;
        return false;
    }
};