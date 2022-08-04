#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
    873. ���쳲����������еĳ��ȣ���Ҫ��
        ʹ�ö�̬�滮��
            ��Ҫʹ�ö�ά����dp����arr[i]��arr[j]��β���쳲����������еĳ���
            һά�������dp�����㣬��������Ӵ���쳲�������������Ҫ��
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        //����һ��������¼��������Ԫ�ص��±�
        unordered_map<int, int> map;
        int n = arr.size();
        int ans = 2;
        //������ά��̬��������ʾ��i��j���쳲��������У���ʼΪ2
        vector<vector<int>> f(n, vector<int>(n, 2));
        //״̬ת�Ʒ���
        for (int i = 0; i < n; i++) {
            //��¼Ԫ���±�
            map[arr[i]] = i;
            //����Ԫ��iǰ���Ԫ�أ��ҵ��쳲���������
            for (int j = i - 1; j >= 0; j--) {
                //��¼Ԫ��i��Ԫ��j֮��Ĳ�ֵ
                int dif = arr[i] - arr[j];
                //�жϲ�ֵ�������ֵ����Ԫ��j��ʣ�µ�Ԫ��Ҳ����Ҫ������ֱ���˳�
                if (dif >= arr[j]) {
                    break;
                }
                //��С�ڣ����ж�ǰ���Ԫ������û��dif
                if (dif < arr[j] && map.find(dif) != map.end()) {
                    //���и���
                    f[i][j] = max(f[i][j], f[j][map[dif]] + 1);
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans == 2 ? 0 : ans;
    }
};