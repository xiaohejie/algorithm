#include<iostream>
using namespace std;
/*
	29-两数相除
		判断特殊情况
		判断正负
		然后使用二分法进行查找
*/
class Solution {
public:
	//使用二分法查找
	long helper(long a, long b) {
		//递归退出条件
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
		//先判断特殊情况
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
			return INT_MAX;		//如果dividend是最小的值，就返回最大值
		}

		//判断正负
		int flag = 1;
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
			flag = -1;
		}

		//使用二分法进行查找
		long a = abs(dividend), b = abs(divisor);
		long ans = helper(a, b);
		if (flag == 1) {
			return ans > INT_MAX ? INT_MAX : ans;
		}
		return -ans;
	}
};