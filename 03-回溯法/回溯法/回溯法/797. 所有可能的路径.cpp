#include<iostream>
#include<vector>
using namespace std;
/*
	���п��ܵ�·����
		ʹ�û��ݷ���
		(���ֻ��ݷ�����leetCode������������ף�����)
*/
class Solution {
public:
	vector<int> ans;
	vector<vector<int>> res;
	void backtrack(vector<vector<int>>& graph, int start) {
		//��ֹ����
		if (start == graph.size()-1) {
			res.push_back(ans);
			return;
		}
			//����graph�ĵ�start������
			for (auto g : graph[start]) {
				ans.push_back(g);
				backtrack(graph, g);
				ans.pop_back();		//����
			}
	};
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		ans.push_back(0);
		int len = graph.size();
		backtrack(graph, 0);
		return res;
	};
};