#include<iostream>
#include<vector>
using namespace std;
/*
	91-���뷽��:
		ʹ�ö�̬�滮
		��ʼ���ַ���Ϊ�վͷ��ؿ�, f[0] = 1;
		//����f[i-1]�ĳ���������f[i]��1��9֮�䣻f[i-2]�ĳ���������f[i]��10��26֮��
		f[i] = f[i-1] + f[i-2];
*/
class Solution {
public:
	int numDecodings(string s) {
		//���ö�̬����
		int len = s.length();
		vector<int> f(len + 1);
		//���г�ʼ��
		f[0] = 1;
		s = ' ' + s;
		//״̬ת�Ʒ���
		for (int i = 1; i <= len; i++ ) {
			int a = s[i] - '0';
			int b = (s[i - 1] - '0') * 10 + s[i] - '0';
			if (a > 0 && a < 10 ) {
				f[i] = f[i - 1];
			}
			if (b >= 10 && b <= 26) {
				f[i] += f[i - 2];
			}
		}
		return f[len];
	}
};