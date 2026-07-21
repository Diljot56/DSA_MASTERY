class Solution {
public:
    vector<string> ans;

    void generator(string &s, int n, int left, int right){
        if(s.length() == n * 2){
            ans.push_back(s);
            return;
        }
        if(left < n){
            s.append("(");
            generator(s, n, left + 1, right);
            s.pop_back();
        }
        if(right < left){
            s.append(")");
            generator(s, n, left, right + 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        generator(s, n, 0, 0);
        return ans;
    }
};