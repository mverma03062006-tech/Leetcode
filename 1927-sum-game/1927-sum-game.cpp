class Solution {
public:
    bool sumGame(string num) {
        int firstsum=0,secondsum=0;
        int countl=0,countr=0;
        int i=0,j=num.length()-1;
        while(i<j){
            if(num[i]!='?'){
                firstsum+=num[i]-'0';
            }
            else countl++;
            if(num[j]!='?'){
                secondsum+=num[j]-'0';
            }
            else countr++;
            i++,j--;
        }
        int diff = firstsum - secondsum;
        int qdiff = countl - countr;

        if (qdiff % 2 != 0)
            return true;

        return diff * 2 != -9 * qdiff;
    }
};