#include "iostream"
#include "vector"
#include "algorithm"
using namespace::std;
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()==0)return 0;
        int len=s.length();
        vector<int>dp(len,0);
        dp[0]=0;
        for(int i=1;i<len;i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i]=(i>=2?dp[i-2]:0)+2;
                }else if(i-1-dp[i-1]>=0&&dp[i-1-dp[i-1]]=='('){
                    dp[i]=dp[i-1]+2+(i-2-dp[i-1]>=0?dp[i-2-dp[i-1]]:0);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
int main(){
    Solution s;
    cout<<s.longestValidParentheses("()");
}