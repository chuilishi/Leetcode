#include "iostream"
#include "vector"
using namespace::std;
class Solution {
    int dp[30005][0];
    //dp[i][0]表示第i天（处理数组第i项时）手上拥有的最大现金数
    //0表示当前持有的是现金不是股票,所以我们是从dp[0][0]=0开始的,如果买了就是dp[0][1]=-price[0]


public:
    int maxProfit(vector<int>& prices) {
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<prices.size();i++){
            dp[i][0]=max(dp[i-1][1]+prices[i],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
        }
        return dp[prices.size()-1][0];
    }
};