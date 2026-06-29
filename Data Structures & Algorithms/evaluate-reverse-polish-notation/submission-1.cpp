class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" ||
               tokens[i] == "-" ||
               tokens[i] == "*" ||
               tokens[i] == "/"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if(tokens[i] == "+"){
                    int val = a + b;
                    s.push(val);
                }
                else if(tokens[i] == "-"){
                    int val = a - b;
                    s.push(val);
                }
                else if(tokens[i] == "*"){
                    int val = a * b;
                    s.push(val);
                }
                else{
                    int val = a / b;
                    s.push(val);
                }
            }
            else{
                int num = stoi(tokens[i]);
                s.push(num);
            }
        }
        return s.top();
    }
};
