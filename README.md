# 动态规划

主要问题：看不出有什么递推关系。

关键，每个都遍历了一遍

i在前面，j把0到i-1都遍历一遍


### 状态定义本身就是很复杂的事情.

### 不要想着动态规划思想能够通吃所有动态规划做的题.

### 因为状态定义和递推公式和动态规划思想本身并没有什么关系,考验的就是思维能力.

### 动态规划思想本身只是给你一个框架,找到状态定义和递推的方法就能解决问题,但是这俩东西本身不是什么单纯的套路

## 当然我们仍然有一些针对这两个东西的原则

状态定义:

1. 概括所有状态
   丑数中:所有只为2,3,5乘起来的数
   股票中:在所有天中,买状态的利润和卖状态的利润
2. 答案是dp[n]



丑数

思想同样是每次都做一次选择.

当然,需要观察到后面的丑数肯定是 **前面丑数与某个数相乘等于后面的丑数** 这个性质

又观察到 **一个数和2,3,5分别相乘就是所有可能的状态** 这个性质

(小tips:不要乱加else!!!!)
