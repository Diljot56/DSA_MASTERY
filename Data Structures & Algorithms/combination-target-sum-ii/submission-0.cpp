class Solution {
public:
    vector<vector<int>> V;

    void magic(int n, vector<int>& nums, vector<int>& v, int sum, int size, int target){
        if(sum == target){
            V.push_back(v);
            return;
        }
        if(n >= size){
            return;
        }
        if(sum > target){
            return;
        }
        sum += nums[n];
        v.push_back(nums[n]);
        magic(n + 1, nums, v, sum, size, target);

        sum -= nums[n];
        v.pop_back();
        int next = n + 1;
        while (next < size && nums[next] == nums[n]){
            next++;
        }
        magic(next, nums, v, sum, size, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        int sum = 0;
        magic(0, nums, v, sum, nums.size(), target);
        return V;
    }
};
