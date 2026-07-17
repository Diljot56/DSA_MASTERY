class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sc;
        int a = 0;
        int m = 0;
        for(int i = 0; i < s.length(); i++){
            while(sc.count(s[i])){
                sc.erase(s[a]);
                a++;
            }
            sc.insert(s[i]);
            m = max(m, i - a + 1);
        }
        return m;
    }
};
