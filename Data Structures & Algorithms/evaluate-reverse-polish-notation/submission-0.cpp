class Solution {
public:
    int applyOp(int a, int b, char op) {
        switch(op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return b != 0 ? a / b : 0;
        }
        return 0;
    }   
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string c : tokens){
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int res = applyOp(b, a, c[0]);
                s.push(res);
            }
            else{
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};
