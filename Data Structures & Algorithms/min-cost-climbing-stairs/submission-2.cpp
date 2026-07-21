class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int prev2 = cost[0];
        int prev = cost[1];
        for(int i = 2; i < cost.size(); i++){
            int cur = cost[i] + min(prev, prev2);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};
