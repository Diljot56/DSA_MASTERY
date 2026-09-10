class Solution {
public:
    int find(int idx1, int idx2, string& text1, string& text2, vector<vector<int>> &dp){
        if(idx1 >= text1.length() || idx2 >= text2.length()){
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1 + find(idx1 + 1, idx2 + 1, text1, text2, dp);
        }
        return dp[idx1][idx2] = 0 + max(find(idx1 + 1, idx2, text1, text2, dp),
                       find(idx1, idx2 + 1, text1, text2, dp));
        
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return find(0, 0,text1, text2, dp);
    }
};
