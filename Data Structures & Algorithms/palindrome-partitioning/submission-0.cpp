class Solution {
public:
    vector<vector<string>> p;
    vector<string> v;

    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void find(string s, int start){
        if(start == s.length()){
            p.push_back(v);
            return;
        }

        for(int end = start; end < s.length(); end++){
            if(isPalindrome(s, start, end)){
                v.push_back(s.substr(start, end - start + 1));
                find(s, end + 1);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        find(s, 0);
        return p;
    }
};
