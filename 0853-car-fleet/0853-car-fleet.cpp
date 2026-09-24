class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,int,greater<int>>map;
        int n=position.size();
        for(int i=0;i<n;i++){
            map[position[i]]=speed[i];
        }
    int fleet=0;
    float lasttime=0;
        for(auto it=map.begin();it!=map.end();it++){
           
            float t=(float)(target-it->first)/it->second;
            if(t>lasttime){
                fleet++;
                lasttime=t;
            }
        }
        return fleet;
    }
};