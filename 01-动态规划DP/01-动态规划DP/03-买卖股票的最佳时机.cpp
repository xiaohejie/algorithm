#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    1����¼����֮ǰ�����Ʊ����Сֵ
    2����¼����������Ʊ������
    3���������������֮ǰ��������������ȣ��ó�����֮ǰ���������
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pMin = prices[0], pMax = 0;
        if (prices.size() <= 1) {
            return 0;
        }
        for (auto& price : prices) {
            pMax = max(pMax, price - pMin);
            pMin = min(pMin, price);
        }
        return pMax;
        
    }
};