class Solution {
public:
    vector<vector<int>> V;

    void magic(int n, vector<int>& nums, vector<int>& v, int sum, int target){
        if(n >= nums.size()){
            return;
        }
        if(sum == target){
            V.push_back(v);
            return;
        }
        if(sum > target){
            return;
        }
        v.push_back(nums[n]);
        magic(n, nums, v, sum + nums[n], target);

        v.pop_back();
        magic(n + 1, nums, v, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> v;
        magic(0, nums, v, 0, target);
        return V;
    }
};
