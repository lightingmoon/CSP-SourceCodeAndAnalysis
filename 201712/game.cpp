/*
*positon:http://118.190.20.162/view.page?gpid=T67
*/
#include<bits/stdc++.h>
using namespace std;
bool a[1005];
int main()
{
    ios::sync_with_stdio(false);
    int n, k;                                       // 读入数据
    cin >> n >> k;
    memset(a, false, sizeof(a));                // 模拟队列
    int l = 1, m = 1, j;                        // 进行n-1次游戏,第n - 1 出队后直接跳出循环
    for(int i = 1; i < n; i++) {                // 保存每一轮游戏开始报数的小盆友
        j = m;
        while(true) {
            if(j > n) j = 1;
            if( !a[j] &&(l % k == 0 || (l % 10) == k) )   break;
            if(!a[j]) {
                l++;
            }
            j++;
        }
        l++;
        a[j++] = true;                           // 置出队标记
        if(i == n - 1) break;                    // 直接跳出
        if(j > n)   j = 1;
        while(a[j]) {                           // 找下一个开始报数小盆友
            j++;
            if(j > n)
                j = 1;
        }
        m = j;
    }
    for(int i = 1; i <= n; i++)                 // 输出赢家
        if(!a[i])   cout << i << "\n";
    return 0;
}
/*
*summary:   数组模拟即可，用循环来模拟报数过程,注意初始化
*/
