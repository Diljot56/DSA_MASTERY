class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0;
        int l = 0;
        for(int r = 1; r < prices.size(); r++){
            if(prices[l] < prices[r]){
                m = max(m, prices[r] - prices[l]);
            }
            else{
                l = r;
            }
        }
        return m;
    }
};
