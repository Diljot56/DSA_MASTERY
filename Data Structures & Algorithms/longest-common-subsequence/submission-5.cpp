class Solution {
public:
    // int find(int idx1, int idx2, string& text1, string& text2, vector<vector<int>> &dp){
    //     if(idx1 >= text1.length() || idx2 >= text2.length()){
    //         return 0;
    //     }
    //     if(dp[idx1][idx2] != -1){
    //         return dp[idx1][idx2];
    //     }
    //     if(text1[idx1] == text2[idx2]){
    //         return dp[idx1][idx2] = 1 + find(idx1 + 1, idx2 + 1, text1, text2, dp);
    //     }
    //     return dp[idx1][idx2] = 0 + max(find(idx1 + 1, idx2, text1, text2, dp),
    //                    find(idx1, idx2 + 1, text1, text2, dp));
        
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        // return find(0, 0,text1, text2, dp);
        for(int i = l1 - 1; i >= 0; i--){
            for(int j = l2 - 1; j >= 0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else{
                    dp[i][j] = 0 + max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};
