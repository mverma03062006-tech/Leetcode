class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp,mp2;
        for(int i=0;i<ransomNote.length();i++){
            mp[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.length();i++){
            mp2[magazine[i]]++;
        }
        for(auto it:ransomNote){
            if(mp[it]>mp2[it])return false;
        }
        return true;
    }
};