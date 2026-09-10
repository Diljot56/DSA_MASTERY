class Solution {
public:
    int find(int i, vector<int> &prices,bool have, vector<vector<int>> &dp){
        if(i >= prices.size()){
            return 0;
        }
        if(dp[i][have] != -1){
            return dp[i][have];
        }
        if(have){
            return dp[i][have] = max(prices[i] + find(i + 2, prices, false, dp),
                       find(i + 1, prices, true, dp));
        }
        return dp[i][have] = max(-prices[i] + find(i + 1, prices, true, dp),
                   find(i + 1, prices, false, dp));
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return find(0, prices, false, dp);
    }
};
