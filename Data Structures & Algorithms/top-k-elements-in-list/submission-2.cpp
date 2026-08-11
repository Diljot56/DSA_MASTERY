class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto &it : freq){
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = nums.size(); i >= 1; i--){
            for(auto x : bucket[i]){
                ans.push_back(x);
            }
            if(ans.size() == k){
                break;
            }
        }
        return ans;
    }
};
