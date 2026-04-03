class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        std::sort(piles.begin(), piles.end());

        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());
        int k;

        while(l < r){

            k = l + ((r-l)/2);
            int time_remaining = h;
            
            for(const int &banana : piles){
                int time = std::ceil(static_cast<double>(banana) / static_cast<double>(k));
                time_remaining -= time;
            }

            if(time_remaining < 0){
                l = k + 1;
            }else{
                r = k;
            }
        }

        return r;
    }

};
