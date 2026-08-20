class Solution {
public:
    bool check(string s,string d){
        bool flag=false;
        for(int i=0;i<s.length();i++){
            if(s[i]!=d[i]&&flag)return false;
            if(s[i]!=d[i])flag=true;
        }
        if(!flag)return false;
        return true;
    }
    int bfs(string begin,string end,vector<string>& word){
        queue<pair<string,int>>q;
        unordered_set<string> visited;
        visited.insert(begin);
        q.push({begin,1});
        while(!q.empty()){
            auto [s,level]=q.front();
            q.pop();
             if(s==end)return level;
            for(int i=0;i<word.size();i++){
               if(!visited.count(word[i])&&check(word[i],s)){
                visited.insert(word[i]);
                q.push({word[i],level+1});
               }

            }
        }
        return 0;
    }
    int ladderLength(string begin, string end, vector<string>& word) {
        bool found=false;
        int ans=0;
        for(int i=0;i<word.size();i++){
            if(end==word[i]){
                found=true;
                break;
            }
        }
        if(!found)return 0;
        return bfs(begin,end,word);
    }
};