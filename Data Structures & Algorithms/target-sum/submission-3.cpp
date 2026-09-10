class Solution {
public:
    int find(int i, vector<int> &nums, int calc, int target, vector<vector<int>> &dp, int sum){
        if(i >= nums.size()){
            if(calc == target){
                return 1;
            }
            return 0;
        }
        if(dp[i][calc + sum] != -1){
            return dp[i][calc + sum];
        }
        return dp[i][calc + sum] = find(i + 1, nums, calc + nums[i], target, dp, sum) + 
                             find(i + 1, nums, calc - nums[i], target, dp, sum);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int x : nums){
            sum += x;
        }
        if(target > sum || target < -sum){
            return 0;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));
        return find(0, nums, 0, target, dp, sum);
    }
};
