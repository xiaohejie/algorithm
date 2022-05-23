#include<iostream>
using namespace std;
/*
	插入排序：
		假设前n-1个已经排好序，将第n个放到前n-1个中,使得前n-1个排好序
		从第一个开始到最后一个，进行上述排序
*/
void intsert(int* arr, int n) {
	//假设前n-1个已经排好序
	//对第n个数进行排序
	int key = arr[n];
	int i = n;
	//从最后一个数即第n-1个数开始比较
	while (key < arr[i - 1]) {
		arr[i] = arr[i - 1];
		i--;
		if (i == 0) {
			break;
		}
	}
	arr[i] = key;
}
void insertSort(int* arr, int n) {
	int i = 1;
	//从第二个数开始比较
	while(i < n){
		intsert(arr, i);
		i++;
	}
}
int main() {
	int arr[] = { 6,4,83,4,1,0,53,8,4,59,53 };

	insertSort(arr, 11);

	for (int i = 0; i <= 10; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;

	return 0;
}