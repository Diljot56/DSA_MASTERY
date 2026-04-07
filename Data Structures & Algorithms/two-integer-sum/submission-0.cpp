class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            for(auto &[a, b] : m){
                if(target - nums[i] == a && b != i){
                    return {i, b};
                }
            }
        }
        return {};
    }
};
