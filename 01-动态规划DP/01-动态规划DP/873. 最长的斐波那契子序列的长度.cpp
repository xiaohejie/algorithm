#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
    873. 最长的斐波那契子序列的长度（重要）
        使用动态规划：
            需要使用二维数组dp：以arr[i]和arr[j]结尾的最长斐波那契字数列的长度
            一维数组进行dp不满足，会忽略连接处的斐波那契数列数列要求
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        //创建一个容器记录遍历过得元素的下标
        unordered_map<int, int> map;
        int n = arr.size();
        int ans = 2;
        //创建二维动态容器，表示从i到j的最长斐波那契数列，初始为2
        vector<vector<int>> f(n, vector<int>(n, 2));
        //状态转移方程
        for (int i = 0; i < n; i++) {
            //记录元素下标
            map[arr[i]] = i;
            //遍历元素i前面的元素，找到最长斐波那契数列
            for (int j = i - 1; j >= 0; j--) {
                //记录元素i和元素j之间的差值
                int dif = arr[i] - arr[j];
                //判断差值，如果差值大于元素j，剩下的元素也不需要遍历，直接退出
                if (dif >= arr[j]) {
                    break;
                }
                //若小于，就判断前面的元素中有没有dif
                if (dif < arr[j] && map.find(dif) != map.end()) {
                    //进行更新
                    f[i][j] = max(f[i][j], f[j][map[dif]] + 1);
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans == 2 ? 0 : ans;
    }
};