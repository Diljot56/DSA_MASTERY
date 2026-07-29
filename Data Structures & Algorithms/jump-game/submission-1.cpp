class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)return true;
        int energy = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(energy < 0)return false;
            if(energy < nums[i]){
                energy = nums[i] - 1;
            }
            else{
                energy--;
            }
        }
        return true;
    }
};
