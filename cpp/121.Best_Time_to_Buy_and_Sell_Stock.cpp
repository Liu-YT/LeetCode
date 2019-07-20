/* solution 1 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)  return 0;

        int maxP[prices.size()];
        int minP[prices.size()];

        minP[0] = prices[0];
        maxP[prices.size()-1] = prices[prices.size()-1];

        for(int i = 1; i < prices.size(); ++i)
            minP[i] = min(prices[i], minP[i-1]);

        for(int j = prices.size() - 2; j >= 0; j--)
            maxP[j] = max(prices[j], maxP[j+1]);

        int profit = 0;
        for(int i = 0; i < prices.size() - 1; ++i) {
            if(maxP[i] - minP[i] > profit)
                profit = maxP[i] - minP[i];
        }
        return profit;
    }
};


/* solution 2 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)  return 0;
        int minP = INT_MAX;
        int res = 0;
        for(auto p : prices) {
            res = max(p - minP, res);
            minP = min(minP, p);
        }
        return res;
    }
};
