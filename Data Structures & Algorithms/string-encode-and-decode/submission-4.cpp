class Solution {
public:

    string encode(vector<string>& strs) {
        string st;
        for(int i = 0; i < strs.size(); i++){
            int len = strs[i].length();
            st += to_string(len);
            st += '#';
            st += strs[i];
        }
        return st;
    }

    vector<string> decode(string s) {
        vector<string> v;
        int i = 0;
        int size = s.length();
        while(i < size){
            string c;
            while(i < size && s[i] != '#'){
                c += s[i];
                i++;
            }
            i++;
            int len = stoi(c);
            string temp = s.substr(i, len);
            v.push_back(temp);
            i += len;
        }
        return v;
    }
};
