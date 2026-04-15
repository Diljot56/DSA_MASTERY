class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right){
            if(numbers[left] + numbers[right] == target && numbers[left] != numbers[right]){
                left++;
                right++;
                break;
            }
            if(numbers[left] + numbers[right] < target){
                left++;
            }
            else{
                right--;
            }
        }
        return {left, right};
    }
};
