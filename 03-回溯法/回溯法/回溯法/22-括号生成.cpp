#include<iostream>
#include<vector>
using namespace std;
/*
	�������ɣ�
	ʹ�û��ݷ���
		��������С��nʱ{
			��Ҫ����������
			Ȼ��ݹ�
			����
		}
		��������С��������ʱ{
			��Ҫ����������
			Ȼ��ݹ�
			����
		}
*/
class Solution {
	vector<string> ans;
public:
	void backtrack(int left, int right, int n, string& s) {
		//��ֹ����
		if (left + right == n * 2) {
			ans.push_back(s);
			return;
		}
		if (left < n) {
			s += "(";
			backtrack(left + 1, right, n, s);
			s.pop_back();
		}
		if (right < left) {
			s += ")";
			backtrack(left, right + 1, n, s);
			s.pop_back();
		}
	}
	vector<string> generateParenthesis(int n) {
		string s = "";
		backtrack(0, 0 , n, s);
		return ans;
	}
};