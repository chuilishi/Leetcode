# 动态规划

主要问题：看不出有什么递推关系。

关键，每个都遍历了一遍

i在前面，j把0到i-1都遍历一遍

### 状态定义本身就是很复杂的事情.

### 不要想着动态规划思想能够通吃所有动态规划做的题.

### 因为状态定义和递推公式和动态规划思想本身并没有什么关系,考验的就是思维能力.

### 动态规划思想本身只是给你一个框架,找到状态定义和递推的方法就能解决问题,但是这俩东西本身不是什么单纯的套路

## 当然我们仍然有一些针对这两个东西的原则

重要的来了:

**状态定义:**

1. 概括所有状态
   丑数中:所有只为2,3,5乘起来的数
   股票中:在所有天中,买状态的利润和卖状态的利润
2. 答案是dp[n]

**状态转移:**

1. 从某种情况开始
2. 分析每一次的选择

最长有效括号:

选择:

对于dp[i]处的 )

1. 如果前面是 ( ,就加
2. 如果前面是 ) ,就找到最终结束的那个地方dp[i-1-dp[i-1]],看看是不是 (

只有这两种情况,就出来了

tips: leetcode数组范围检查很严格,最好在前面加一些范围性的判定
