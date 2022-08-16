#include<iostream>
#include<vector>
using namespace std;
/*
	��ϣ�
		����
*/
class Solution1 {
	vector<vector<int>> ans;
	vector<int> res;
	void dfs(int start, int n, int k) {
		if (k == res.size()) {
			ans.push_back(res);
			return;
		}
		if (res.size() + n - start + 1 < k) {
			return;
		}
		for (int i = start; i <= n; i++) {
			res.push_back(i);
			dfs(i+1, n, k);
			res.pop_back();
		}
	}
public:
	vector<vector<int>> combine(int n, int k) {
		dfs(1, n, k);
		return ans;
	}
};

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> res;
	void backTrack(int n, int k, int start) {
		//��ֹ����
		if (res.size() == k) {
			ans.push_back(res);
			return;
		}
		//�����ǩres�еĸ������Ϻ���ʣ��ĸ�����С��k����ֱ�ӻ���
		if (res.size() + n - start + 1 < k) {
			return;
		}

		for (int i = start; i <= n; i++) {
			res.push_back(i);
			backTrack(n, k, i+1);
			res.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		backTrack(n, k, 1);
		return ans;
	}
};