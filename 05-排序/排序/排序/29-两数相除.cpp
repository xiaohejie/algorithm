#include<iostream>
using namespace std;
/*
	29-�������
		�ж��������
		�ж�����
		Ȼ��ʹ�ö��ַ����в���
*/
class Solution {
public:
	//ʹ�ö��ַ�����
	long helper(long a, long b) {
		//�ݹ��˳�����
		if (a < b) {
			return 0;
		}
		long count = 1;
		long tb = b;
		while ((tb + tb) <= a) {
			count = count + count;
			tb = tb + tb;
		}
		return count + helper(a - tb, b);
	}
	int divide(int dividend, int divisor) {
		//���ж��������
		if (dividend == 0) {
			return 0;
		}
		if (divisor == 1) {
			return dividend;
		}
		if (divisor == -1) {
			if (dividend > INT_MIN) {
				return dividend;
			}
			return INT_MAX;		//���dividend����С��ֵ���ͷ������ֵ
		}

		//�ж�����
		int flag = 1;
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
			flag = -1;
		}

		//ʹ�ö��ַ����в���
		long a = abs(dividend), b = abs(divisor);
		long ans = helper(a, b);
		if (flag == 1) {
			return ans > INT_MAX ? INT_MAX : ans;
		}
		return -ans;
	}
};