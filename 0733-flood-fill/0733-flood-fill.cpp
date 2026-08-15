class Solution {
public:
    bool valid(int r,int c,vector<vector<int>>& image){
        int m=image.size();
        int n=image[0].size();
        if(r<0||r>m-1||c<0||c>n-1)return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int start=image[sr][sc];
        if(start==color)return image;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                if(valid(r,c+1,image)&&image[r][c+1]==start){
                    image[r][c+1]=color;
                    q.push({r,c+1});
                }
                if(valid(r-1,c,image)&&image[r-1][c]==start){
                    image[r-1][c]=color;
                    q.push({r-1,c});
                }
                if(valid(r+1,c,image)&&image[r+1][c]==start){
                    image[r+1][c]=color;
                    q.push({r+1,c});
                }if(valid(r,c-1,image)&&image[r][c-1]==start){
                    image[r][c-1]=color;
                    q.push({r,c-1});
                }
            }
        }
        return image;
    }
};