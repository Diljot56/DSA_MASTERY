class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sc;
        int l = 0;
        int m = 0;
        for(int r = 0; r < s.length(); r++){
            while(sc.count(s[r])){
                sc.erase(s[l]);
                l++;
            }
            sc.insert(s[r]);
            m = max(m, r - l + 1);
        }
        return m;
    }
};
