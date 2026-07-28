class Solution {
public:
    bool find(int idx, int sum, vector<int> &nums, int totalSum, vector<vector<int>> &dp){
        if(sum == totalSum / 2){
            return true;
        }
        if(idx >= nums.size() || sum > totalSum / 2)return false;
        if(dp[idx][sum] != -1)return dp[idx][sum];
        return dp[idx][sum] = find(idx + 1, sum + nums[idx], nums, totalSum, dp) ||
                              find(idx + 1, sum, nums, totalSum, dp);         
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }
        if(totalSum % 2 != 0)return false;
        vector<vector<int>> dp(nums.size(), vector<int>(totalSum / 2 + 1, -1));
        return find(0, 0, nums, totalSum, dp);
    }
};
