#include<iostream>
using namespace std;
int n, tol;
int vis[55], a[55];
void dfs(int step)
{
    if (step == n + 1)          //搜索完毕
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";        //依次输出全排列
        cout << endl;
        tol++;                  // 满足条件为一种情况总个数 + 1
        return;                 //return非常重要，一定记得返回上一步才可以进行下一次搜索
    }
    for (int i = 1; i <= n; i++)    //遍历
    {
        if (vis[i] == 0)        //没有访问过
        {
            a[step] = i;        
            vis[i] = 1;             //标记为1表示已经搜索过
            dfs(step + 1);          //将下一步搜索
            vis[i] = 0;             //标记为0继续下一次搜索防止重复
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