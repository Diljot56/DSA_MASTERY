class Solution {
public:
    // int find(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
    //     if(i >= coins.size() || amount < 0){
    //         return 0;
    //     }
    //     if(amount == 0){
    //         return 1;
    //     }
    //     if(dp[i][amount] != -1){
    //         return dp[i][amount];
    //     }
    //     return dp[i][amount] = find(i, amount - coins[i], coins, dp) + 
    //                            find(i + 1, amount, coins, dp);
    // }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        // return find(0, amount, coins, dp);
        int n = coins.size();
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j <= amount; j++){
                if(j >= coins[i]){
                    dp[i][j] = dp[i][j - coins[i]];
                }
                dp[i][j] += dp[i + 1][j];
            }
        }
        return dp[0][amount];
    }
};
