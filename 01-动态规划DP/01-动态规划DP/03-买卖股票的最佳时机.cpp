#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    1、记录今天之前买入股票的最小值
    2、记录今天卖出股票的利润
    3、今天最大利润与之前的最大利润进行相比，得出今天之前的最大利润
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pMin = prices[0], pMax = 0;
        if (prices.size() <= 1) {
            return 0;
        }
        for (auto& price : prices) {
            pMax = max(pMax, price - pMin);
            pMin = min(pMin, price);
        }
        return pMax;
        
    }
};