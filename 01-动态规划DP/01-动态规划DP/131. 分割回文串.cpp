#include<iostream>
#include<vector>
using namespace std;
/*
	131. �ָ���Ĵ�
*/
class Solution {
	vector<vector<string>> ans;
	vector<string> path;
public:
	vector<vector<string>> partition(string s) {
		//������̬����
		int n = s.size();
		vector<vector<bool>> f(n, vector<bool>(n));
		//״̬ת�Ʒ���
		for (int j = 0; j < n; j++) {
			for (int i = 0; i <= j; i++) {
				if (i == j) {
					f[i][j] = 1;
				}
				else {
					f[i][j] = (s[i] == s[j]) && (i + 1 > j - 1 || f[i + 1][j - 1]);
				}
			}
		}
		//�õ��ַ����д����ﵽ�����ǻ����Ӵ�������dfs
		dfs(s, 0, f);
		return ans;
	}
	void dfs(string s, int index, vector<vector<bool>> f) {
		//��ֹ����
		if (index == s.length()) {
			ans.push_back(path);
			return;
		}
		for (int i = index; i < s.length(); i++) {
			if (0 == f[index][i]) {
				continue;
			}
			else {
				path.push_back(s.substr(index, i - index + 1));
				dfs(s, i+1, f);
				//����
				path.pop_back();
			}
		}
	}
};