#include<iostream>
using namespace std;
/*
	���������У�
		(1)�Ƚ���ȥ�ز���(isFirst)��
			������Ѿ�����ans�ĺ�һ��λ�ã������ڽ����жϵ�λ�ã������ַ�����num[pos]����˵�����ַ�������
			�����ڵĻ�����˵�����Լ���
		(2)dfs�жϣ�
			���pos == nums.size():
				����ĩβ��ֱ���˳�
			����Ļ�
				�ж�num[pos]�Ƿ����(ans�Ƿ�Ϊ�� || num[pos]>=ans.back()) && isFirst��{
					ans.push_back(num[pos])
					if(ans.size() >= 2){
						res.push_back(ans);
					}
					//����
					dfs(nums, pos, pos + 1, ans, res);	//����������һ��
					ans.pop_back();				//�ѵ�ǰ������³���
				}
				dfs(nums, last, pos + 1, ans, res);		//pos+1����
*/