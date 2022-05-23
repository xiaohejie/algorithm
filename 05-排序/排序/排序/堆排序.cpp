#include<iostream>
using namespace std;
/*
	堆排序：
		主要是针对树
*/
void heapify(int* tree, int n, int i) {
	if (i >= n) {
		return;
	}
	int c1 = 2 * i + 1;
	int c2 = 2 * i + 2;
	int max = i;
	if (c1 < n && tree[max] < tree[c1]) {
		max = c1;
	}
	if (c2 < n && tree[max] < tree[c2]) {
		max = c2;
	}
	if (max != i) {
		swap(tree[i], tree[max]);
		//递归
		heapify(tree, n, max);
	}
}

void buildHeap(int* tree, int n) {
	int lastNode = n - 1;
	int parent = (lastNode - 1) / 2;
	for (int i = parent; i >= 0; i--) {
		heapify(tree, n, i);
	}
}

void heapSort(int* tree, int n) {
	//建立堆
	buildHeap(tree, n);

	for (int i = n - 1; i >= 0; i--) {
		swap(tree[i], tree[0]);
		heapify(tree, i, 0);
	}
}
int maindui() {
	int tree[] = { 2,5,3,1,10,4 };
	int n = 6;
	//heapify(tree, n, 0);
	buildHeap(tree, n);
	/*heapSort(tree, n);*/
	for (int i = 0; i < n; i++) {
		cout << tree[i] << " ";
	}
	return 0;
}