class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2)return max(nums[0], nums[1]);
        int prev2 = nums[0];
        int prev = max(nums[1], nums[0]);
        for(int i = 2; i < nums.size(); i++){
            int cur = max(prev, nums[i] + prev2);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};
