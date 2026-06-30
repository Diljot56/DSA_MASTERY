class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for(int i = 0; i < position.size(); i++){
           v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());

        stack<double> s;
        for(int i = v.size() - 1; i >= 0; i--){
            double time = (double)(target - v[i].first) / v[i].second;
            if(!s.empty() && s.top() >= time){
                continue;
            }
            else{
                s.push(time);
            }
        }
        return s.size();
    }
};
