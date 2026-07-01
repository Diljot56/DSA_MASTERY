class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = 0;
        for(int i = 0; i < piles.size(); i++){
            if(m < piles[i]){
                m = piles[i];
            }
        }
        int k = 0;
        int left = 1;
        int right = m;
        int ans = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            for(int i = 0; i < piles.size(); i++){
                if(piles[i] < mid){
                    k++;
                }
                else{
                    k += (piles[i] + mid - 1) / mid;
                }
            }
            if(k > h){
                left = mid + 1;
            }
            else{
                ans = mid;
                right = mid - 1;
            }
            k = 0;
        }
        return ans;
    }
};
