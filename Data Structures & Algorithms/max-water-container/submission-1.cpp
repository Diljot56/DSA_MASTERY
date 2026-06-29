class Solution {
public:
    int maxArea(vector<int>& heights) {
        int m = 0;
        int left = 0;
        int right = heights.size() - 1;
        while(left < right){
            int w = (right - left) * min(heights[left], heights[right]);
            m = max(m , w);
            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return m;
    }
};
