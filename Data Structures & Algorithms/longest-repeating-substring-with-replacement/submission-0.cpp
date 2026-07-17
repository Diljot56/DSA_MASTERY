class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int ans = 0;
        unordered_set<char> sc(s.begin(), s.end());
        for(char c : sc){
            int count = 0;
            for(int r = 0; r < s.length(); r++){
                if(s[r] == c){
                    count++;
                }
                while(r - l + 1 - count > k){
                    if(s[l] == c){
                        count--;
                    }
                    l++;
                }
                ans = max(ans, r - l + 1);
            }
            l = 0;
        }
        return ans;
    }
};
