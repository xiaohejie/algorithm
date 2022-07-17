#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
	外观数列：
		动态规划
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
		ans.push_back("1");		//第0个数
		ans.push_back("11");	//第1个数	
		//动态规划：前两个数已经存入ans中
		for (int i = 2; i < n; i++) {
			//根据i-1计算i
			string tmpStr;
			string prev = ans[i - 1];		//记录前一个字符串
			char curr = prev[0];
			//遍历ans[i - 1]
			int count = 1;
			for (int j = 1; j < prev.size(); j++) {
				if (prev[j] != curr) {
					tmpStr.append(to_string(count));
					tmpStr += curr;
					//更新当前字符
					curr = prev[j];
					count = 1;
				}
				else {
					//否则两个字符相等
					count++;
				}
			}
			//遍历到最后
			tmpStr.append(to_string(count));
			tmpStr.append(to_string(curr));

			//将第i个的答案放进去
			ans.push_back(tmpStr);
		}
		return ans[n - 1];
	}
};