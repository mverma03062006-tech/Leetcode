class Solution {
public:
    int strStr(string a, string key) {
        int ans=-1;
        if(a.length()<key.length())return ans;
        for(int i=0;i<=a.length()-key.length();i++){
            int j=0,k=i;
            while(j<key.length()&&a[k]==key[j]){
                j++;
                k++;
            }
            if(j==key.length()){
                ans=i;
                break;
            }
        }
        return ans;
    }
};