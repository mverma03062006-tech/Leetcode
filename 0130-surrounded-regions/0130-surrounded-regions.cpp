class Solution {
public:
    bool valid(int i,int j ,int m,int n){
    if(i>m-1||j>n-1||j<0||i<0)return false;
    return true;
}
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                board[i][0]='Y';
            }
            if(board[i][n-1]=='O'){
                q.push({i,n-1});
                board[i][n-1]='Y';
            }         
        }
        for(int i=1;i<n-1;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                board[0][i]='Y';
            }
            if(board[m-1][i]=='O'){
                q.push({m-1,i});
                board[m-1][i]='Y';
            }
        }
         while(!q.empty()){
              auto [r,c]= q.front();
              q.pop();
              if(valid(r-1,c,m,n)){
                if(board[r-1][c]=='O'){
                    q.push({r-1,c});
                    board[r-1][c]='Y';
                }
              }
              if(valid(r+1,c,m,n)){
                if(board[r+1][c]=='O'){
                    q.push({r+1,c});
                    board[r+1][c]='Y';
                }
              }
              if(valid(r,c-1,m,n)){
                if(board[r][c-1]=='O'){
                    q.push({r,c-1});
                    board[r][c-1]='Y';
                }
              }
              if(valid(r,c+1,m,n)){
                if(board[r][c+1]=='O'){
                    q.push({r,c+1});
                    board[r][c+1]='Y';
                }
              }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='Y')board[i][j]='O';
            }
        }
    }
};