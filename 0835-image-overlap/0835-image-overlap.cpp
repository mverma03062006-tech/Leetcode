class Solution {
public:
    int shift(int i,int j,vector<vector<int>>& a,vector<vector<int>>& b){
        int lsc=0,rsc=0;
        int br=0;
        for(int ar=i;ar<a.size();ar++){
            int bc=0;
            for(int ac=j;ac<a.size();ac++){
                if(a[ar][ac]==1&&a[ar][ac]==b[br][bc])lsc++;
                if(a[ar][bc]==1&&a[ar][bc]==b[br][ac])rsc++;
                bc+=1;
            }
            br++;
        }
        return max(lsc,rsc);
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxoverlap=0;
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img2.size();j++){
                maxoverlap=max(maxoverlap,shift(i,j,img1,img2));
                maxoverlap=max(maxoverlap,shift(i,j,img2,img1));
            }
        }
        return maxoverlap;
    }
};