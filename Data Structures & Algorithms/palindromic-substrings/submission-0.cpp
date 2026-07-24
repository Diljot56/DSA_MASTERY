class Solution {
public:
    bool isPalindrome(string &s, int left, int right){
        if(left >= right)return true;
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = i; j < s.length(); j++){
                if(isPalindrome(s, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};
