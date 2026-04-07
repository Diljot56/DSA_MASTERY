class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(int i = 0; i < strs.size(); i++){
            int length = strs[i].length();
            s += to_string(length) + "#" + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        int i = 0;
        while(i < s.length()){
            string c;
            while(i < s.length() && s[i] != '#'){
                c += s[i];
                i++;
            }
            i++;
            int x = stoi(c);
            string temp = s.substr(i, x);
            v.push_back(temp);
            i += x;
        }
        return v;
    }
};
