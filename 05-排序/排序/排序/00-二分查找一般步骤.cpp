#include<iostream>
using namespace std;
/*
	二分查找一般步骤：
		1、建模：分为蓝红区域，确定isBlue()
		2、确定返回l还是r
		3、套用下方算法模板
		4、根据实际情况，加入后续处理
*/
/*
	l = -1, r = N;
	while(l + 1 != r){
		m = (l + r)/2;
		if(isBlue(m)){
			l = m;
		}else{
			r = m
		}
	}
	return l or r;

*/