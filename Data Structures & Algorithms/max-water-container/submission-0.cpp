class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int m = INT_MIN;
        while(left < right){
            int w = (right - left) * min(heights[left], heights[right]);
            m = max(m, w);
            if(heights[left] < heights[right]) left++;
            else right--;
        }
        return m;
    }
};
