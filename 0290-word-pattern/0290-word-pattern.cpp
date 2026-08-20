class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        stringstream ss(s);
        string word;

        int i = 0;

        while (ss >> word) {
            if (i == pattern.size())
                return false;

            if (mp.count(pattern[i]) && mp[pattern[i]] != word)
                return false;

            if (rev.count(word) && rev[word] != pattern[i])
                return false;

            mp[pattern[i]] = word;
            rev[word] = pattern[i];

            i++;
        }

        return i == pattern.size();
    }
};