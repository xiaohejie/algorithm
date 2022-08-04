#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	473. 火柴拼正方形
*/
class Solution {
    bool dfs(vector<int>& matchsticks, vector<int>& edges, int edge, int index) {
        //递归中止条件
        if (index == matchsticks.size()) {
            //说明已经遍历到最后
            return true;
        }
        //开始遍历四条边
        for (int i = 0; i < 4; i++) {
            if (matchsticks[index] + edges[i] > edge) {
                //如果当前长度加上当前火柴大于edge，就跳过
                continue;
            }
            //否则的话，就加上
            edges[i] += matchsticks[index];
            //递归下一条边
            if (dfs(matchsticks, edges, edge, index+1)) {
                //如果下一条边为true
                return true;
            }
            //否则的话，就回溯
            edges[i] -= matchsticks[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < matchsticks.size(); i++) {
            sum += matchsticks[i];
        }
        if (sum % 4 != 0) {
            return false;
        }
        //进行排序
        sort(matchsticks.begin(), matchsticks.end());
        vector<int> edges(4);
        int edge = sum / 4;
        return dfs(matchsticks, edges, edge, 0);
    }
};
