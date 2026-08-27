class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        string ans="";
       for(int i=0;i<target.length();i++){
        for(char c=target[i]+1;c<='z';c++){
            if(mp.find(c)!=mp.end()){
                string temp=target.substr(0,i);
                temp+=c;
                unordered_map<char,int>rem=mp;
                rem[c]--;
                if(rem[c]==0)rem.erase(c);
                for(char x='a';x<='z';x++){
                    if(rem.find(x)!=mp.end()){
                        while(rem[x]>0){
                            temp+=x;
                            rem[x]--;
                        }
                    }
                }
                if(ans==""||ans>temp){
                    ans=temp;
                }
            }
        }
            if(mp.find(target[i])!=mp.end()){
                mp[target[i]]--;
                if(mp[target[i]]==0)mp.erase(target[i]);
            }
            else break;
       }
       return ans;
    }
};