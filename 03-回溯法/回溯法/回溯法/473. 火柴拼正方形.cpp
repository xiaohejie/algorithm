#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
/*
    473. ���ƴ������(�Լ�����΢����ͼ)
*/
class Solution {
public:
    //edges����¼������       edge��������ʵ��Ӧ�еĳ���     index���õ��ڼ������
    bool backtrack(vector<int>& matchsticks, vector<int>& edges, int edge, int index) {
        //�ж���ֹ����
        if (index == matchsticks.size()) {
            return true;
        }

        //����������
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i] + matchsticks[index] > edge) {
                //�����ǰ���ȼ���diindex�����ĳ��ȴ��ڱ߳�
                continue;       //������һ��Ͱ
            }
            edges[i] += matchsticks[index];     //��index���������i��Ͱ��
            if(backtrack(matchsticks, edges, edge, index+1)){   //�ݹ�ķ�����һ�����
                return true;            // ��һ�������óɹ���ֱ�ӷ���true
            }
            //����
            edges[i] -= matchsticks[index];     //����index������Ͱi���ó�
        }
        return false;           //�����index������޷������κ�һ��Ͱ���ͷ���false
    }
    bool makesquare(vector<int>& matchsticks) {
        //��ͣ��������4�ı���
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) {
            return false;
        }
        int edge = sum / 4;     //�߳�
        vector<int> edges(4);   //�����ε�4����    
        //����(�Ӵ�С)
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        //����
        return backtrack(matchsticks, edges, edge, 0);
    }
};