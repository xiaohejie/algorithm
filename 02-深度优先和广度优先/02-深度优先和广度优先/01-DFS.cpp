#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int len = 0;
    int ans = 0;
    long  maxScore = 0;//要注意为long，防止溢出
    vector<vector<int>>children;//记录各个节点的子节点坐标

    int dfs(int node) {//利用dfs，dfs的返回值是以此节点为根形成的树，所有节点的总和
        long score = 1;//记录当前节点的分数
        int size = len - 1;//用来记录与当前节点相连的父亲节点所连的一系列节点的总和
        for (int c : children[node]) {//计算以每个节点为根结点的子树的大小
            int t = dfs(c);//返回的是该节点左子树，或者右子树的大小
            score *= t;//分数进行记录
            size -= t;//用来记录与当前节点相连的父亲节点所连的一系列节点的总和
        }
        if (node != 0) {//0的分数只有左右子树的乘积，没有父亲节点
            score *= size;
        }
        if (score == maxScore) {
            ++ans;
        }
        else if (score > maxScore) {
            maxScore = score;
            ans = 1;
        }
        return len - size;//总节点 - 父亲节点所连节点总和 = 自身为根节点的树大小
    }

    int countHighestScoreNodes(vector<int>& parents) {
        this->len = parents.size();//所有节点的数量
        this->children.resize(len);
        for (int i = 0; i < len; ++i) {
            if (parents[i] != -1) { //不是根节点
                children[parents[i]].push_back(i);//以父亲节点的坐标作为索引，加入子节点坐标
            }
        }
        dfs(0);
        return ans;
    }
};