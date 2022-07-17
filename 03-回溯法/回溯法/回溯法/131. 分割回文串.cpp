#include<iostream>
#include<vector>
using namespace std;
/*
	131. �ָ���Ĵ�
		��ʹ�ö�̬�滮����¼�ַ����ַ�֮���ܲ��ܹ��ɻ���
		��ʹ�û��ݷ������б���
*/
class Solution {
private:
	int len = 0;
	vector<vector<bool>>f;
	vector<vector<string>> ans;
	vector<string>path;
public:
	void dfs(string s, int index) {
		//��ֹ����
		if (index == len) {
			ans.push_back(path);
			return;
		}
		for (int i = index; i < len; i++) {
			if (f[index][i] == 0) {
				//�����ɻ��Ĵ�
				continue;
			}
			//���ɻ��Ĵ�
			path.push_back(s.substr(index, i - index + 1));
			//������һ��λ�õ�dfs
			dfs(s, i + 1);
			//�ָ��ֳ�
			path.pop_back();
		}
	}
	vector<vector<string>> partition(string s) {
		len = s.length();
		//��ʼ��
		f = vector<vector<bool>>(len, vector<bool>(len));
		//״̬����(Ҫ���п�ʼ����)
		for (int j = 0; j < len; j++) {
			for (int i = 0; i <= j; i++) {
				if (i == j) {
					f[i][j] = 1;
				}
				else {
					//��������Ϊ�п���f[i+1][j-1]������
					f[i][j] = (s[i] == s[j]) && (i + 1 > j - 1 || f[i + 1][j - 1]);
				}
			}
		}
		//���л���
		dfs(s, 0);
		return ans;
	}
};