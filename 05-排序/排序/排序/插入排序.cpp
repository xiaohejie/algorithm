#include<iostream>
using namespace std;
/*
	��������
		����ǰn-1���Ѿ��ź��򣬽���n���ŵ�ǰn-1����,ʹ��ǰn-1���ź���
		�ӵ�һ����ʼ�����һ����������������
*/
void intsert(int* arr, int n) {
	int key = arr[n];
	int i = n;
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