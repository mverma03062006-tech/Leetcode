class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string>v;
        int l=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')count++;

            while(count == k) {
                v.push_back(s.substr(l, i-l+1));

                if(s[l] == '1')
                    count--;

                l++;
            }
        }
        if(v.size()==0)return "";
        string mini=v[0];
        for(auto it:v){
            if(it.length()<mini.length()){
                mini=it;
            }
        }
        int mi=mini.length();
        vector<string>t;
        for(auto it:v){
            if(it.length()==mi){
                t.push_back(it);
            }
        }
        sort(t.begin(),t.end());
        return t[0];
    }
};