class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int l = 0;
        int ans = 0;
        int maxf = 0;
        for(int r = 0; r < s.length(); r++){
            m[s[r]]++;
            maxf = max(maxf, m[s[r]]);
            if(r - l + 1 - maxf > k){
                m[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
