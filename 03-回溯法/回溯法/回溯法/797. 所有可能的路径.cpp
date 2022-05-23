#include<iostream>
#include<vector>
using namespace std;
/*
	所有可能的路径：
		使用回溯法：
		(两种回溯方法，leetCode和这个，搞明白，明天)
*/
class Solution {
public:
	vector<int> ans;
	vector<vector<int>> res;
	void backtrack(vector<vector<int>>& graph, int start) {
		//中止条件
		if (start == graph.size()-1) {
			res.push_back(ans);
			return;
		}
			//遍历graph的第start个数组
			for (auto g : graph[start]) {
				ans.push_back(g);
				backtrack(graph, g);
				ans.pop_back();		//回溯
			}
	};
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		ans.push_back(0);
		int len = graph.size();
		backtrack(graph, 0);
		return res;
	};
};