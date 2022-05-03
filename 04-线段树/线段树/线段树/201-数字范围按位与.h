#pragma once
#include <iostream>
using namespace std;
//�ҳ����λ��������λ��ͬ����ֱ����Ϊ0
int msb(int num) {
	int count = 0;
	while (num) {
		count++;
		num /= 2;
	}
	return count - 1;
}
//������ĵ�iλ��Ϊ1
int setBit(int result, int i) {
	return (result | (1 << i));
}
//ȡ�����ĵ�iΪ
int getBit(int num, int i){
	return ((num >> i) & 1);
}
int rangeBitwiseAnd(int left, int right) {
	int msb1 = msb(left);
	int msb2 = msb(right);
	if (msb1 != msb2) {
		return 0;
	}
	//��ȵĻ����ʹ����λ����
	int msb = msb1;
	int result = 0;
	while (msb >= 0){
		//��left��right�ĵ�msbλ�Ƿ����
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