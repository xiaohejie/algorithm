#pragma once
#include <iostream>
using namespace std;
//找出最高位，如果最高位不同，则直接置为0
int msb(int num) {
	int count = 0;
	while (num) {
		count++;
		num /= 2;
	}
	return count - 1;
}
//将结果的第i位变为1
int setBit(int result, int i) {
	return (result | (1 << i));
}
//取该数的第i为
int getBit(int num, int i){
	return ((num >> i) & 1);
}
int rangeBitwiseAnd(int left, int right) {
	int msb1 = msb(left);
	int msb2 = msb(right);
	if (msb1 != msb2) {
		return 0;
	}
	//相等的话，就从最高位往下
	int msb = msb1;
	int result = 0;
	while (msb >= 0){
		//看left和right的第msb位是否相等
		int l = getBit(left, msb);
		int r = getBit(right, msb);
		if (l != r) {
			return result;
		}
		else if (l == 1) {
			result = setBit(result, msb);
		}
		msb--;
	}
	return result;
}