class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
		
		if(k == 0 || prices.size() <= 1)	return 0;

		int maxP = 0;
		if (k >= (prices.size() / 2)) {
			for (int i = 1; i < prices.size(); i++) {
				if (prices[i] > prices[i - 1])
					maxP += prices[i] - prices[i - 1];
			}
			return maxP;
		}

		vector<vector<int>> profit(k+1, vector<int>(prices.size()+1, 0));

		for(int i = 1; i <= k; ++i) {
			int balance = -prices[0];
            for(int j = 1; j < prices.size(); j++) {
                profit[i][j] = max(profit[i][j - 1], balance + prices[j]);
                balance = max(balance, profit[i - 1][j - 1] - prices[j]);
            }
		}
		
		return profit[k][prices.size()-1];
    }
};

