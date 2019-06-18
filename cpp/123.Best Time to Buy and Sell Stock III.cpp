//  You may complete at most two transactions.

// 解法1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		
		if(prices.size() <= 1)	return 0;

		int pre[prices.size()] = {0};
		int post[prices.size()] = {0};

		// 求某天前(包括当天)成交的最大利润
		int prebase = prices[0];
		int preMaxProfit = 0;
		for(int i = 1; i < prices.size(); ++i) {
			preMaxProfit = max(preMaxProfit, prices[i] - prebase);
			pre[i] = preMaxProfit;
			prebase = min(prebase, prices[i]);
		}

		// 求某天后成交的最大利润
		int postBase = prices[prices.size() - 1];
		int postMaxProfit = 0;
		for(int i = prices.size() - 1; i >= 1; --i) {
			postMaxProfit = max(postMaxProfit, postBase - prices[i]);
			post[i-1] = postMaxProfit;
			postBase = max(postBase, prices[i]);
		}

		int maxProfit = 0;
		for(int i = 0; i < prices.size(); ++i)
			for(int j = 0; j < prices.size(); ++j)
				maxProfit = max(maxProfit, pre[i] + post[i]);

		return maxProfit;
    }
};


// 解法2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		
		if(prices.size() <= 1)	return 0;

		// 交易两次，得到的利润
		int profit[3][prices.size()];

		// init
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < prices.size(); ++j)
				profit[i][j] = 0;

		for(int i = 1; i <= 2; ++i) {
			int balance = -prices[0];
            for(int j = 1; j < prices.size(); j++) {
                profit[i][j] = max(profit[i][j - 1], balance + prices[j]);
                balance = max(balance, profit[i - 1][j - 1] - prices[j]);
            }
		}
		
		return profit[2][prices.size()-1];
    }
};



// 解法3
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		
		if(prices.size() <= 1)	return 0;

		int buy1 = INT_MIN, buy2 = INT_MIN;
		int sell1 = 0, sell2 = 0;

		for(int price : prices){
            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);
            buy2 = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);
        }
		return sell2;
    }
};