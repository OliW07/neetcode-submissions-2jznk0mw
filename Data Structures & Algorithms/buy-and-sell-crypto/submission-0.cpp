class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 999;
        int maxProfit = 0;

        for(const int price : prices){
            maxProfit = max(maxProfit, price-min_price);
            min_price = min(min_price, price);
        }

        return maxProfit;

    }
};
