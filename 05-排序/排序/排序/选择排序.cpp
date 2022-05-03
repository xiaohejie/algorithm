#include<iostream>
using namespace std;
/*
*	选择排序：
*		从数组中找到最大值，并将它放到最后一个位置
*/
//找出最大值的位置
int findMaxPos(int* arr, int n) {
	int max = arr[0];
	int pos = 0;
	for (int i = 1; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
			pos = i;
		}
	}
	return pos;
}
void selectionSort(int* arr, int n) {
	while (n > 1) {		//使用n > 1是因为有n - 1 > 0（大于等于无所谓）;
		int pos = findMaxPos(arr, n);
		int temp = arr[pos];
		arr[pos] = arr[n - 1];
		arr[n - 1] = temp;
		n--;
	}
	
}
int mainxuanze() {
	int arr[] = { 6,4,83,4,1,0,53,8,4,59,53 };

	selectionSort(arr, 11);

	for (int i = 0; i <= 10; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

	return 0;
}