class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        for(int i=0;i<s1.length();i++){
            mp[s1[i]]++;
        }
        int l=0,r=0;
        unordered_map<char,int>mp2;
        while(r<s2.length()){
            mp2[s2[r]]++;
             if(r - l + 1 == s1.length()) {

                if(mp2 == mp)
                    return true;

                mp2[s2[l]]--;

                if(mp2[s2[l]] == 0)
                    mp2.erase(s2[l]);

                l++;
            }
            r++;
        }
        return false;
    }
};