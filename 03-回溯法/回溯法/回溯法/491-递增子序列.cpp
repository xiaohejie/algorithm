#include<iostream>
using namespace std;
/*
	递增子序列：
		(1)先进性去重操作(isFirst)：
			如果从已经加入ans的后一个位置，到正在进行判断的位置，存在字符等于num[pos]，就说明该字符不合理
			不存在的话，就说明可以加入
		(2)dfs判断：
			如果pos == nums.size():
				到达末尾，直接退出
			否则的话
				判断num[pos]是否合理（(ans是否为空 || num[pos]>=ans.back()) && isFirst）{
					ans.push_back(num[pos])
					if(ans.size() >= 2){
						res.push_back(ans);
					}
					//回溯
					dfs(nums, pos, pos + 1, ans, res);	//继续处理下一个
					ans.pop_back();				//把当前放入的吐出来
				}
				dfs(nums, last, pos + 1, ans, res);		//pos+1继续
*/