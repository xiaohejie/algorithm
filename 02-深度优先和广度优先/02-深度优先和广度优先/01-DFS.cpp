#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int len = 0;
    int ans = 0;
    long  maxScore = 0;//Ҫע��Ϊlong����ֹ���
    vector<vector<int>>children;//��¼�����ڵ���ӽڵ�����

    int dfs(int node) {//����dfs��dfs�ķ���ֵ���Դ˽ڵ�Ϊ���γɵ��������нڵ���ܺ�
        long score = 1;//��¼��ǰ�ڵ�ķ���
        int size = len - 1;//������¼�뵱ǰ�ڵ������ĸ��׽ڵ�������һϵ�нڵ���ܺ�
        for (int c : children[node]) {//������ÿ���ڵ�Ϊ�����������Ĵ�С
            int t = dfs(c);//���ص��Ǹýڵ��������������������Ĵ�С
            score *= t;//�������м�¼
            size -= t;//������¼�뵱ǰ�ڵ������ĸ��׽ڵ�������һϵ�нڵ���ܺ�
        }
        if (node != 0) {//0�ķ���ֻ�����������ĳ˻���û�и��׽ڵ�
            score *= size;
        }
        if (score == maxScore) {
            ++ans;
        }
        else if (score > maxScore) {
            maxScore = score;
            ans = 1;
        }
        return len - size;//�ܽڵ� - ���׽ڵ������ڵ��ܺ� = ����Ϊ���ڵ������С
    }

    int countHighestScoreNodes(vector<int>& parents) {
        this->len = parents.size();//���нڵ������
        this->children.resize(len);
        for (int i = 0; i < len; ++i) {
            if (parents[i] != -1) { //���Ǹ��ڵ�
                children[parents[i]].push_back(i);//�Ը��׽ڵ��������Ϊ�����������ӽڵ�����
            }
        }
        dfs(0);
        return ans;
    }
};