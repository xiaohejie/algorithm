#include<iostream>
#include<vector>
using namespace std;
/*
	120. ��������С·����
		ʹ�ö�̬�滮
*/
//���������£�����һ���Ǵ�������
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int m = triangle.size();
		cout << m << endl;
		//ʹ�ô�������
		//������̬����
		vector<int> f(m + 1);		//���￼�ǵ���m+1������Ϊ������j+1��
		//��ʼ��
		//״̬ת�Ʒ���
		for (int i = m - 1; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				f[j] = min(f[j], f[j + 1]) + triangle[i][j];
				// cout << f[j] <<  " ";
			}
			//cout << endl;
		}
		return f[0];
	}
};