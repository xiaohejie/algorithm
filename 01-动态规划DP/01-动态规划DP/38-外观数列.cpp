#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
	������У�
		��̬�滮
*/
class Solution {
public:
	string countAndSay(int n) {
		if (n == 0) {
			return "";
		}
		if (n == 1) {
			return "1";
		}
		vector<string> ans;
		ans.push_back("1");		//��0����
		ans.push_back("11");	//��1����	
		//��̬�滮��ǰ�������Ѿ�����ans��
		for (int i = 2; i < n; i++) {
			//����i-1����i
			string tmpStr;
			string prev = ans[i - 1];		//��¼ǰһ���ַ���
			char curr = prev[0];
			//����ans[i - 1]
			int count = 1;
			for (int j = 1; j < prev.size(); j++) {
				if (prev[j] != curr) {
					tmpStr.append(to_string(count));
					tmpStr += curr;
					//���µ�ǰ�ַ�
					curr = prev[j];
					count = 1;
				}
				else {
					//���������ַ����
					count++;
				}
			}
			//���������
			tmpStr.append(to_string(count));
			tmpStr.append(to_string(curr));

			//����i���Ĵ𰸷Ž�ȥ
			ans.push_back(tmpStr);
		}
		return ans[n - 1];
	}
};