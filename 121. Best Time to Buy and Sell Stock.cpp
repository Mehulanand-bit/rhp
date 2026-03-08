class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int min_price=prices[0];
        for(int i=0;i<prices.size();i++){
             int profit=prices[i]-min_price;
             maxprofit=max(maxprofit,profit);
             min_price=min(min_price,prices[i]);
        }
        return maxprofit;
    }
};
