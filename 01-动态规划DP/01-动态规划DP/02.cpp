#include <iostream>
#include <vector>
using namespace std;
//��1���ݹ�
bool subset_rec(vector<int> arr, int i, int s) {
	//1��Ѱ����ֹ����
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


//��2���ݹ飨�����⣬��Խ�磩
bool subset_dp(vector<int> arr, int s) {
	//�����ά�����¼�Ƿ���������
	vector<vector<int>> ans(arr.size(), vector<int>(s + 1));
	//1����0��ȫΪtrue
	for (int i = 0; i < arr.size(); i++) {
		ans[i][0] = true;
		//cout << ans[i][0] << "  ";
	}
	//cout << endl;
	//2����0��ȫΪfalse������arr[0]��
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
	//���������н��бȽ�
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
	//��һ�������п����ܲ����ҵ���Ϊs�������ҵõ�����true����֮false
	vector<int> arr;
	srand((unsigned)time(NULL));
	int num = rand() % 10;
	cout << num << endl;
	for (int i = 0; i < 10; i++) {
		arr.push_back(rand() % 10);
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "�ݹ鷨��ã�" << subset_rec(arr, 9, 2) << endl;

	cout << "���淨��ã�" << subset_dp(arr, 2) << endl;
	return 0;
}