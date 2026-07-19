class Solution {
public:

    void generator(vector<string> &v, string s, int left, int right, int n){
        if(s.length() == n * 2){
            if(left == right){
                v.push_back(s);
            }
            return;
        }
        if(left > n || right > n) return;
        if(right > left) return;
        s.append("(");
        left++;
        generator(v, s, left, right, n);
        s.pop_back();
        left--;
        s.append(")");
        right++;
        generator(v, s, left, right, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s;
        s.append("(");
        generator(v, s, 1, 0, n);
        return v;
    }
};
