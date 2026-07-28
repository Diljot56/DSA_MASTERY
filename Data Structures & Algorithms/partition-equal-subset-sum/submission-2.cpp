class Solution {
public:
    bool find(int idx, int sum, vector<int> &nums, int totalSum){
        if(sum == totalSum / 2){
            return true;
        }
        if(idx >= nums.size() || sum > totalSum / 2)return false;
        bool res = find(idx + 1, sum + nums[idx], nums, totalSum) ||
                   find(idx + 1, sum, nums, totalSum); 
        return res;        
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }
        if(totalSum % 2 != 0)return false;
        return find(0, 0, nums, totalSum);
    }
};
