class Solution {
public:
    int find(int idx, int prev, vector<int> &nums, vector<vector<int>> &dp){
        if(idx == nums.size())return 0;
        if(dp[idx][prev + 1] != -1)return dp[idx][prev + 1];
        int len = 0 + find(idx + 1, prev, nums, dp);
        if(prev == -1 || nums[idx] > nums[prev]){
            len = max(len, 1 + find(idx + 1, idx, nums, dp));
        }
        return dp[idx][prev + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return find(0, -1, nums, dp);
    }
};
