#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
/*
    473. 火柴拼正方形(自己再稍微画个图)
*/
class Solution {
public:
    //edges：记录四条边       edge：正方形实际应有的长度     index：用到第几根火柴
    bool backtrack(vector<int>& matchsticks, vector<int>& edges, int edge, int index) {
        //判断终止条件
        if (index == matchsticks.size()) {
            return true;
        }

        //遍历四条边
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i] + matchsticks[index] > edge) {
                //如果当前长度加上diindex根火柴的长度大于边长
                continue;       //尝试下一个桶
            }
            edges[i] += matchsticks[index];     //第index根火柴放入第i个桶中
            if(backtrack(matchsticks, edges, edge, index+1)){   //递归的放置下一根火柴
                return true;            // 下一根火柴放置成功就直接返回true
            }
            //回溯
            edges[i] -= matchsticks[index];     //将第index根火柴从桶i中拿出
        }
        return false;           //如果第index根火柴无法放入任何一个桶，就返回false
    }
    bool makesquare(vector<int>& matchsticks) {
        //求和，如果不是4的倍数
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }
        int edge = sum / 4;     //边长
        vector<int> edges(4);   //正方形的4条边    
        //排序(从大到小)
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        //回溯
        return backtrack(matchsticks, edges, edge, 0);
    }
};