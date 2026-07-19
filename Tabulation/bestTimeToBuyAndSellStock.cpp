// best time to buy and sell stock
// leetcode problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// leetcode 121

// ============================
// Approach 1: Brute Force
// Time Complexity: O(n²)
// Space Complexity: O(1)
// ============================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int ans = 0;

        // Try every buy day
        for (int i = 0; i < n; i++) {

            // Try every sell day after buying
            for (int j = i + 1; j < n; j++) {

                // Update maximum profit
                ans = max(ans, prices[j] - prices[i]);
            }
        }

        return ans;
    }
};


// ============================
// Approach 2: Suffix Maximum
// Time Complexity: O(n)
// Space Complexity: O(n)
// ============================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> suffixMax(n);

        // Last day's maximum is itself
        suffixMax[n - 1] = prices[n - 1];

        // Build suffix maximum array
        for (int i = n - 2; i >= 0; i--) {

            suffixMax[i] = max(prices[i], suffixMax[i + 1]);
        }

        int ans = 0;

        // Calculate profit if bought on each day
        for (int i = 0; i < n; i++) {

            ans = max(ans, suffixMax[i] - prices[i]);
        }

        return ans;
    }
};

// ============================
// Approach 3: Greedy (Optimal)
// Time Complexity: O(n)
// Space Complexity: O(1)
// ============================

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Lowest buying price seen so far
        int minPrice = INT_MAX;

        // Maximum profit
        int maxProfit = 0;

        for (int price : prices) {

            // Found a cheaper buying price
            minPrice = min(minPrice, price);

            // Profit if sold today
            int profit = price - minPrice;

            // Update answer
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};
