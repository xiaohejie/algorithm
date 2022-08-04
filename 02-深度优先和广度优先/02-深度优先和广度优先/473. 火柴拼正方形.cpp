#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	473. ���ƴ������
*/
class Solution {
    bool dfs(vector<int>& matchsticks, vector<int>& edges, int edge, int index) {
        //�ݹ���ֹ����
        if (index == matchsticks.size()) {
            //˵���Ѿ����������
            return true;
        }
        //��ʼ����������
        for (int i = 0; i < 4; i++) {
            if (matchsticks[index] + edges[i] > edge) {
                //�����ǰ���ȼ��ϵ�ǰ������edge��������
                continue;
            }
            //����Ļ����ͼ���
            edges[i] += matchsticks[index];
            //�ݹ���һ����
            if (dfs(matchsticks, edges, edge, index+1)) {
                //�����һ����Ϊtrue
                return true;
            }
            //����Ļ����ͻ���
            edges[i] -= matchsticks[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < matchsticks.size(); i++) {
            sum += matchsticks[i];
        }
        if (sum % 4 != 0) {
            return false;
        }
        //��������
        sort(matchsticks.begin(), matchsticks.end());
        vector<int> edges(4);
        int edge = sum / 4;
        return dfs(matchsticks, edges, edge, 0);
    }
};
