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
        sum += nums[n];
        v.push_back(nums[n]);
        magic(n, nums, v, sum, target);

        sum -= nums[n];
        v.pop_back();
        magic(n + 1, nums, v, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> v;
        int sum = 0;
        magic(0, nums, v, sum, target);
        return V;
    }
};
