#include<iostream>
#include<vector>
#include <random>
using namespace std;
/*
	497. ���ص������е������
		�����һ����
		ȷ���õ����Ǹ�������
		�ڴӸþ������������
*/
class Solution {
	vector<int> rangeDot;
	vector<vector<int>>& rects;
public:
	Solution(vector<vector<int>>& rects): rects(rects) {
		//������ʼֵ
		this->rangeDot.push_back(0);
		for (auto& rect : rects) {
			//��ÿ�������еĵ�ĸ����Ž�ȥ
			this->rangeDot.push_back(rangeDot.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
		}
	}
	vector<int> pick() {
		//�����һ���㣬��Χ��rangeDot�ķ�Χ����ȥ��һ���㣩
		int dot = rand() % rangeDot.back() + 1;
		//ȷ���õ�ľ��ε�λ�ã�ʹ�ö��ַ�����
		int l = -1, r = rects.size();
		while (l + 1 != r) {
			int mid = (l + r) / 2;
			if (rangeDot[mid] >= dot) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		//�ҵ�����������������ɵ�
		vector<int> vec = rects[r - 1];
		int x = vec[2] - vec[0] + 1, y = vec[3] - vec[1] + 1;
		return { rand() % x + vec[0], rand() % y + vec[1] };
	}
};