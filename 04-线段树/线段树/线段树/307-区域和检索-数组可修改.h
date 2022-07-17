#pragma once
#include<iostream>
#include <vector>
using namespace std;
/*
	给你一个数组 nums ，请你完成两类查询:
		其中一类查询要求 更新 数组 nums 下标对应的值
		另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
		实现 NumArray 类：

	NumArray(int[] nums) 用整数数组 nums 初始化对象
	void update(int index, int val) 将 nums[index] 的值 更新 为 val
	int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 
	和 （即，nums[left] + nums[left + 1], ..., nums[right]）
*/
class NumArray {
private:
	vector<int> tree;
	int n;
	//构造线段树
	void buildTree(vector<int>& nums, int node, int start, int end) {
		//递归中止条件
		if (start == end) {
			tree[node] = nums[end];
		}
		else {
			int mid = (start + end) / 2;
			int leftNode = 2 * node + 1;
			int rightNode = 2 * node + 2;

			//进行递归
			buildTree(nums, leftNode, start, mid);
			buildTree(nums, rightNode, mid + 1, end);
			tree[node] = tree[leftNode] + tree[rightNode];
		}
	}
	//更新状态树
	void updateTree(int node, int start, int end, int index, int val) {
		//递归中止
		if (start == end) {
			tree[node] = val;
		}
		int mid = (start + end) / 2;
		int leftNode = node * 2 + 1;
		int rightNode = node * 2 + 2;

		//递归
		if (index >= start && index <= mid) {
			updateTree(leftNode, start, mid, index, val);
		}
		else {
			updateTree(rightNode, mid + 1, end, index, val);
		}
		tree[node] = tree[leftNode] + tree[rightNode];
	}
	//给状态数的结点段求和
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
