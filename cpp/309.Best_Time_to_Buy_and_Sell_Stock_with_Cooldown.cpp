class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size < 2)    return 0;
        vector<int> balance(size), buy(size), sell(size);
        buy[0] = -prices[0];
        balance[0] = sell[0] = 0;

        for(int i = 1; i < size; ++i) {
            buy[i] = max(buy[i-1], balance[i-1] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            balance[i] = max(balance[i-1], sell[i-1]);
        }

        return max(buy[size-1], sell[size-1]);
    }
};