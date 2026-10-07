class Solution {
public:
    bool isvalid(string & s){
        int count=0;
        for(char c:s){
            if(c=='(')count++;
            if(c==')'){
                if(count==0)return false;
                count--;
            }
        }
        return count==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>result;
        unordered_set<string>visi;
        queue<string>q;
        q.push(s);
        visi.insert(s);
        bool found=false;
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            if(isvalid(curr)){
                result.push_back(curr);
                found=true;
            }
            if(found)continue;
            for(int i=0;i<curr.length();i++){
                if(curr[i]!='('&&curr[i]!=')')continue;
                string nextstate=curr.substr(0,i)+curr.substr(i+1);
                if(visi.find(nextstate)==visi.end()){
                    visi.insert(nextstate);
                    q.push(nextstate);
                }
            }
        }
        return result;
    }
};