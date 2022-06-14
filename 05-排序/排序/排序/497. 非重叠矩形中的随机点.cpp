#include<iostream>
#include<vector>
#include <random>
using namespace std;
/*
	497. 非重叠矩形中的随机点
		随机找一个点
		确定该点在那个矩形中
		在从该矩形中找随机点
*/
class Solution {
	vector<int> rangeDot;
	vector<vector<int>>& rects;
public:
	Solution(vector<vector<int>>& rects): rects(rects) {
		//给定初始值
		this->rangeDot.push_back(0);
		for (auto& rect : rects) {
			//将每个矩形中的点的个数放进去
			this->rangeDot.push_back(rangeDot.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
		}
	}
	vector<int> pick() {
		//随机找一个点，范围是rangeDot的范围（除去第一个点）
		int dot = rand() % rangeDot.back() + 1;
		//确定该点的矩形的位置：使用二分法查找
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
		//找到随机矩阵后，在随机生成点
		vector<int> vec = rects[r - 1];
		int x = vec[2] - vec[0] + 1, y = vec[3] - vec[1] + 1;
		return { rand() % x + vec[0], rand() % y + vec[1] };
	}
};