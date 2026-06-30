class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // vector<int> pse(heights.size());
        // vector<int> nse(heights.size());
        // stack<int> ps;
        // stack<int> ns;
        // for(int i = 0; i < heights.size(); i++){
        //     while(!ps.empty() && heights[ps.top()] >= heights[i]){
        //         ps.pop();
        //     }
        //     if(ps.empty()){
        //         pse[i] = -1;
        //     }
        //     else{
        //         pse[i] = ps.top();
        //     }
        //     ps.push(i);
        // }

        // for(int i = heights.size() - 1; i >= 0; i--){
        //     while(!ns.empty() && heights[ns.top()] >= heights[i]){
        //         ns.pop();
        //     }
        //     if(ns.empty()){
        //         nse[i] = heights.size();
        //     }
        //     else{
        //         nse[i] = ns.top();
        //     }
        //     ns.push(i);
        // }

        // int m = 0;
        // for(int i = 0; i < heights.size(); i++){
        //     int area = (nse[i] - pse[i] - 1) * heights[i];
        //     m = max(m, area);
        // }
        // return m;

        int m = 0;
        stack<int> s;
        for(int i = 0; i < heights.size(); i++){
            while(!s.empty() && heights[s.top()] > heights[i]){
                int elm = s.top();
                s.pop();
                int nse = i;
                int pse = s.empty() ? -1 : s.top();
                m = max(m, (nse - pse - 1) * heights[elm]);
            }
            s.push(i);
        }

        while(!s.empty()){
            int elm = s.top();
            s.pop();
            int nse = heights.size();
            int pse = s.empty() ? -1 : s.top();
            m = max(m, (nse - pse - 1) * heights[elm]);
        }
        return m;
    }
};
