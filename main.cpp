#include "iostream"
#include "vector"
#include "algorithm"
#include <algorithm>
using namespace::std;
class Solution {
public:
    int nthUglyNumber(int n) {
        int m2=1,m3=1,m5=1;
        vector<int>dp(n+1);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int n2=dp[m2]*2;
            int n3=dp[m3]*3;
            int n5=dp[m5]*5;
            if(n2==min({n2,n3,n5})){
                dp[i]=n2;
                m2++;
            }
            if(n3==min({n2,n3,n5})){
                dp[i]=n3;
                m3++;
            }
            if(n5==min({n2,n3,n5})){
                dp[i]=n5;
                m5++;
            }
        }
        return dp[n];
    }
};