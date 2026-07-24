class Solution {
public:
    int ans = INT_MAX;
    void magic(int n, vector<int>& coins, vector<int>& v, int sum, int amount){
        if(sum == amount){
            if(v.size() < ans){
                ans = v.size();
            }
            return;
        }
        if(n == coins.size()){
            return;
        }
        if(sum > amount){
            return;
        }
        sum += coins[n];
        v.push_back(coins[n]);
        magic(n, coins, v, sum, amount);

        sum -= coins[n];
        v.pop_back();
        magic(n + 1, coins, v, sum, amount);
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> v;
        int sum = 0;
        magic(0, coins, v, sum, amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
