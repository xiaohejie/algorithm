#include <iostream>
#include <vector>
using namespace std;
//法1：递归
bool subset_rec(vector<int> arr, int i, int s) {
	//1、寻找中止条件
	if (s == 0) {
		return true;
	}
	else if (i == 0) {
		return arr[0] == s;
	}
	else if (arr[i] > s) {
		return subset_rec(arr, i - 1, s);
	}
	else {
		return subset_rec(arr, i - 1, s - arr[i]) || subset_rec(arr, i - 1, s);
	}
}


//法2：递归（有问题，会越界）
bool subset_dp(vector<int> arr, int s) {
	//定义二维数组记录是否满足条件
	vector<vector<int>> ans(arr.size(), vector<int>(s + 1));
	//1、第0列全为true
	for (int i = 0; i < arr.size(); i++) {
		ans[i][0] = true;
		//cout << ans[i][0] << "  ";
	}
	//cout << endl;
	//2、第0行全为false，除了arr[0]行
	for (int i = 0; i < s; i++) {
		if (i == arr[0]) {
			ans[0][i] = true;
		}
		else {
			ans[0][i] = false;
		}
		//cout << ans[0][i] << "  ";
	}
	//cout << endl;
	//对其余行列进行比较
	for (int i = 1; i < arr.size(); i++) {
		for (int j = 1; j < s + 1; j++) {
			if (arr[i] > s) {
				ans[i][j] = ans[i - 1][j];
			}
			else {
				ans[i][j] = ans[i - 1][j] || ans[i - 1][j - arr[i]];
			}
			
		}
	}
	return ans[arr.size() - 1][s - 1];
}
int main2() {
	//从一组数组中看看能不能找到和为s的数，找得到返回true，反之false
	vector<int> arr;
	srand((unsigned)time(NULL));
	int num = rand() % 10;
	cout << num << endl;
	for (int i = 0; i < 10; i++) {
		arr.push_back(rand() % 10);
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "递归法求得：" << subset_rec(arr, 9, 2) << endl;

	cout << "动规法求得：" << subset_dp(arr, 2) << endl;
	return 0;
}