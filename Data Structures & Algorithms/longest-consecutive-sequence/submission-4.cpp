class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int best = 1;
        int M = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){
                continue;
            }
            if(nums[i] == nums[i - 1] + 1){
                best++;
                continue;
            }
            M = max(M, best);
            best = 1;
        }
        M = max(M, best);
        return M;
    }
};
