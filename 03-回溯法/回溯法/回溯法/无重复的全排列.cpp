#include<iostream>
using namespace std;
int n, tol;
int vis[55], a[55];
void dfs(int step)
{
    if (step == n + 1)          //�������
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";        //�������ȫ����
        cout << endl;
        tol++;                  // ��������Ϊһ������ܸ��� + 1
        return;                 //return�ǳ���Ҫ��һ���ǵ÷�����һ���ſ��Խ�����һ������
    }
    for (int i = 1; i <= n; i++)    //����
    {
        if (vis[i] == 0)        //û�з��ʹ�
        {
            a[step] = i;        
            vis[i] = 1;             //���Ϊ1��ʾ�Ѿ�������
            dfs(step + 1);          //����һ������
            vis[i] = 0;             //���Ϊ0������һ��������ֹ�ظ�
        }
    }
    return;
}

int main()
{
    cin >> n;
    dfs(1);
    printf("Total=%d", tol);
    return 0;
}