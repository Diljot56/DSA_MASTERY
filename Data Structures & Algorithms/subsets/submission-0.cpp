class Solution {
public:
    vector<vector<int>> V;

    void magic(int n, vector<int>& nums, vector<int>& v, int size){
        if(n >= size){
            V.push_back(v);
            return;
        }   
        v.push_back(nums[n]);
        magic(n + 1, nums, v, size);
        v.pop_back();
        magic(n + 1, nums, v, size);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        magic(0, nums, v, nums.size());
        return V;
    }
};
