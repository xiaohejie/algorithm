#include <iostream>
#include <vector>
#include<time.h>
using namespace std;
int helper_dp(vector<int> arr) {
	vector<int> ans;
	//1、寻找终止条件
	ans.push_back(arr[0]);
	ans.push_back(max(arr[0], arr[1]));
	//2、动态规划条件
	int A = 0, B = 0;
	for (int i = 2; i < arr.size(); i++) {
		A = arr[i] + ans[i - 2];
		B = ans[i - 1];
		ans.push_back(max(A, B));
	}
	return ans[ans.size() - 1];
}
int helper_rec(vector<int> arr, int i) {
	int A = 0, B = 0;
	//1、判断中止条件
	if (i == 0) {
		return arr[0];
	}
	else if (i == 1) {
		return max(arr[0], arr[1]);
	}
	else {
		A = arr[i] + helper_rec(arr, i - 2);
		B = helper_rec(arr, i - 1);
		return max(A, B);
	}
}
int main1() {
	//从一个数组中，不连续选相邻的数组，选出和最大的
	vector<int> arr;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		arr.push_back(rand()%100);
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "最大为:" << endl;
	int ans_dp = helper_dp(arr);
	cout << ans_dp << endl;
	int ans_rec = helper_rec(arr, 9);
	cout << ans_rec << endl;
	return 0;
}