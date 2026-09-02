class Solution {
public:
   
    int titleToNumber(string col) {
        long long ans=0;
        
        for(char ch : col){
            ans=ans*26+(ch-'A'+1);
        }
        return  (int)ans;
    }
};