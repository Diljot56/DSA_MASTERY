class Solution {
public:

    int dfs(int i, string &s, vector<int> &dp){
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return 0;

        int ans = dfs(i + 1, s, dp);
        if(i < s.length() - 1){
            if((s[i] == '1') || (s[i] == '2' && s[i + 1] < '7')){
                ans += dfs(i + 2, s, dp);
            }
        }
        return dp[i] = ans;
    }

    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, -1);
        dp[s.length()] = 1;
        return dfs(0, s, dp);
    }
};
