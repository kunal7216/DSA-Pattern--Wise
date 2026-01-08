// best time to buy and sell stock
// leetcode problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// leetcode 121

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        // Minimum price to buy the stock so far
        int buy_price = prices[0];

        // Maximum profit achievable
        int profit = 0;

        for (int i = 1; i < prices.size(); i++)
        {

            // Update minimum buying price
            if (prices[i] < buy_price)
            {
                buy_price = prices[i];
            }
            else
            {
                // Calculate profit if sold today
                profit = max(profit, prices[i] - buy_price);
            }
        }

        return profit;
    }
};
