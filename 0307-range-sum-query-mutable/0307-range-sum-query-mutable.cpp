class NumArray {
public:
vector<int>num;
vector<int>original;
    NumArray(vector<int>& nums) {
        num=nums;
        original=nums;
        for(int i=1;i<num.size();i++){
            num[i]+=num[i-1];
        }
    }
    
    void update(int index, int val) {
        int diff=original[index]-val;
        original[index]=val;
        for(int i=index;i<num.size();i++){
            num[i]-=diff;
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)return num[right];
        else return num[right]-num[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */