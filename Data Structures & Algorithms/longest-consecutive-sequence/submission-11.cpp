class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int m = 1;
        for(int i = 0; i < nums.size(); i++){
            int a = 1;
            int num = nums[i];
            if(s.count(num - 1))continue;
            while(s.count(num + 1)){
                num++;
                a++;
            }
            m = max(m, a);
        }
        return m;
    }
};
