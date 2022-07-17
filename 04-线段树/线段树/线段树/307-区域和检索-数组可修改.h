#pragma once
#include<iostream>
#include <vector>
using namespace std;
/*
	����һ������ nums ��������������ѯ:
		����һ���ѯҪ�� ���� ���� nums �±��Ӧ��ֵ
		��һ���ѯҪ�󷵻����� nums ������ left ������ right ֮�䣨 ���� ����numsԪ�ص� �� ������ left <= right
		ʵ�� NumArray �ࣺ

	NumArray(int[] nums) ���������� nums ��ʼ������
	void update(int index, int val) �� nums[index] ��ֵ ���� Ϊ val
	int sumRange(int left, int right) �������� nums ������ left ������ right ֮�䣨 ���� ����numsԪ�ص� 
	�� ������nums[left] + nums[left + 1], ..., nums[right]��
*/
class NumArray {
private:
	vector<int> tree;
	int n;
	//�����߶���
	void buildTree(vector<int>& nums, int node, int start, int end) {
		//�ݹ���ֹ����
		if (start == end) {
			tree[node] = nums[end];
		}
		else {
			int mid = (start + end) / 2;
			int leftNode = 2 * node + 1;
			int rightNode = 2 * node + 2;

			//���еݹ�
			buildTree(nums, leftNode, start, mid);
			buildTree(nums, rightNode, mid + 1, end);
			tree[node] = tree[leftNode] + tree[rightNode];
		}
	}
	//����״̬��
	void updateTree(int node, int start, int end, int index, int val) {
		//�ݹ���ֹ
		if (start == end) {
			tree[node] = val;
		}
		int mid = (start + end) / 2;
		int leftNode = node * 2 + 1;
		int rightNode = node * 2 + 2;

		//�ݹ�
		if (index >= start && index <= mid) {
			updateTree(leftNode, start, mid, index, val);
		}
		else {
			updateTree(rightNode, mid + 1, end, index, val);
		}
		tree[node] = tree[leftNode] + tree[rightNode];
	}
	//��״̬���Ľ������
	int queryTree(int node, int start, int end, int right, int left) {
		if (end < left || start > right) {
			return 0;
		}
		else if (start >= left && right >= end) {
			return tree[node];
		}
		else {
			int mid = (start + end) / 2;
			int leftNode = node * 2 + 1;
			int rightNode = node * 2 + 2;

			int sumLeft = queryTree(leftNode, start, mid, right, left);
			int sumRight = queryTree(rightNode, mid + 1, end, right, left);
			return sumLeft + sumRight;
		}

	}
public:
	NumArray(vector<int>& nums): n(nums.size()), tree(n * 4) {
		buildTree(nums, 0, 0, n - 1);
	}

	void update(int index, int val) {
		updateTree(0, 0, n - 1, index, val);
	}

	int sumRange(int left, int right) {
		return queryTree( 0, 0, n - 1, right, left);
	}
};
