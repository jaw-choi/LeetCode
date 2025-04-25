class NumArray {
public:
    vector<int> vec;
    NumArray(vector<int>& nums) {
        for(auto n : nums)
            vec.push_back(n);
    }
    
    int sumRange(int left, int right) {
        int ans = 0;
        for(int i=left;i<=right;i++)
            ans+=vec[i];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */