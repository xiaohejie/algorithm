//#include"πÈ≤¢≈≈–Ú.h"
#include<vector>
#include<iostream>
using namespace std;

void merge(int* a, int L, int R, int M) {
	vector<int> left;
	vector<int> right;
	for (int i = L; i < M; i++) {
		left.push_back(a[i]);
	}
	for (int i = M; i <= R; i++) {
		right.push_back(a[i]);
	}
	/*for (auto& num : left) {
		cout << num << " ";
	}
	cout << endl;
	for (auto& num : right) {
		cout << num << " ";
	}
	cout << endl;*/
	int m = 0, n = 0, k = L;
	while (m < left.size() && n < right.size()) {
		if (left[m] < right[n]) {
			a[k] = left[m];
			m++;
			k++;
		}
		else {
			a[k] = right[n];
			k++;
			n++;
		}
	}
	while (m < left.size()) {
		a[k] = left[m];
		k++;
		m++;
	}
	while (n < right.size()) {
		a[k] = right[n];
		k++;
		n++;
	}
}
void mergeSort(int* a, int L, int R) {
	if (L == R) {
		return;
	}
	else {
		int M = (L + R) / 2;
		mergeSort(a, L, M);
		mergeSort(a, M + 1, R);
		merge(a, L, R, M + 1);
	}
}

int main1() {
	int a[] = { 2,8,9,10,11,3,4,5,6,7 };
	mergeSort(a, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}