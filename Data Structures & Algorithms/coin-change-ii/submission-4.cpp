class Solution {
public:
    int find(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(i >= coins.size() || amount < 0){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        return dp[i][amount] = find(i, amount - coins[i], coins, dp) + 
                               find(i + 1, amount, coins, dp);
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return find(0, amount, coins, dp);
    }
};
