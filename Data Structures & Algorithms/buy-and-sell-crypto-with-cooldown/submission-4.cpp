class Solution {
public:
    // int find(int i, vector<int> &prices, bool have, vector<vector<int>> &dp){
    //     if(i >= prices.size()){
    //         return 0;
    //     }
    //     if(dp[i][have] != -1){
    //         return dp[i][have];
    //     }
    //     if(have){
    //         return dp[i][have] = max(prices[i] + find(i + 2, prices, false, dp),
    //                    find(i + 1, prices, true, dp));
    //     }
    //     return dp[i][have] = max(-prices[i] + find(i + 1, prices, true, dp),
    //                find(i + 1, prices, false, dp));
    // }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 2, vector<int>(2, 0));
        // return find(0, prices, false, dp);
        for(int i = prices.size() - 1; i >= 0; i--){
            dp[i][0] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
            dp[i][1] = max(prices[i] + dp[i + 2][0], dp[i + 1][1]);
        }
        return dp[0][0];
    }
};
