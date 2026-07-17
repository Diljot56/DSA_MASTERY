class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0;
        int r = prices.size() - 1;
        int l = r - 1;
        while(l >= 0){
            int p = prices[r] - prices[l];
            if(prices[r] < prices[l]){
                r = l;
            }
            l--;
            m = max(m, p);
        }
        return m;
    }
};
