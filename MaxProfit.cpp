//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/
/*

int maxProfit(int k, std::vector<int>& prices) {
    if (prices.empty()) return 0;
    if (k >= prices.size() / 2) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) maxProfit += prices[i] - prices[i - 1];
        }
        return maxProfit;
    }
    
    std::vector<std::vector<int>> dp(k + 1, std::vector<int>(prices.size(), 0));
    for (int i = 1; i <= k; i++) {
        int localMax = dp[i - 1][0] - prices[0];
        for (int j = 1; j < prices.size(); j++) {
            dp[i][j] = std::max(dp[i][j - 1], prices[j] + localMax);
            localMax = std::max(localMax, dp[i - 1][j] - prices[j]);
        }
    }
    return dp[k][prices.size() - 1];
}
*/

#include <climits>

int maxProfit(int k, int prices[], int n) {
    if (n == 0) return 0;
    if (k >= n / 2) {
        int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) maxProfit += prices[i] - prices[i - 1];
        }
        return maxProfit;
    }
    
    int dp[k + 1][n];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= k; i++) {
        int localMax = dp[i - 1][0] - prices[0];
        for (int j = 1; j < n; j++) {
            dp[i][j] = std::max(dp[i][j - 1], prices[j] + localMax);
            localMax = std::max(localMax, dp[i - 1][j] - prices[j]);
        }
    }
    return dp[k][n - 1];
}

In this code, we first check if the prices array is empty. If it is, we return 0 because no transactions can be made. Then, we check if the maximum number of transactions is greater than or equal to half the number of days. If it is, we can make as many transactions as we want, so we simply add up all the profits from consecutive days where the price increases.

If the maximum number of transactions is less than half the number of days, we use dynamic programming to find the maximum profit. We create a 2D array dp where dp[i][j] represents the maximum profit from at most i transactions by the jth day. For each day, we calculate the maximum profit from making a transaction on that day or not making a transaction. We keep track of the maximum profit from i - 1 transactions and buying a stock on a previous day in localMax. Finally, we return the maximum profit from k transactions by the last day.

This solution works because it considers all possible numbers of transactions up to k and all possible days to make the transactions. It uses dynamic programming to avoid recalculating the maximum profit for the same number of transactions and days. I hope this helps! Let me know if you have any other questions
