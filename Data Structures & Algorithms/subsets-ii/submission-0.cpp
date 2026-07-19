class Solution {
public:

    void subset(vector<int> &nums, int i, vector<int> &v, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back({v});
            return;
        }
        v.push_back(nums[i]);
        subset(nums, i + 1, v, ans);

        v.pop_back();
        int next = i + 1;
        while(next < nums.size() && nums[next] == nums[i]){
            next++;
        }
        subset(nums, next, v, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        vector<vector<int>> ans;
        subset(nums, 0, v, ans);
        return ans;
    }
};
