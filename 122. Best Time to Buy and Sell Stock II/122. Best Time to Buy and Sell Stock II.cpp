class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profitIfJustBought = -prices[0], profitIfJustSold = 0; 
        for (int i = 1; i < prices.size() - 1; ++i) {
            int price = prices[i];
            int tempJustBought = max(profitIfJustBought, profitIfJustSold - price);
            int tempJustSold = max(profitIfJustSold, profitIfJustBought + price);
            profitIfJustBought = tempJustBought;
            profitIfJustSold = tempJustSold;
        }
        // the max profit is when the last is a sell operation. you will get higher profit always
        return max(profitIfJustSold, profitIfJustBought + prices.back());
    }
};
