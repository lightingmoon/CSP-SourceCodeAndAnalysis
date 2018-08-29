/*
*positon:http://118.190.20.162/view.page?gpid=T63
*/
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n < 30){                                                 // 区分钱的档次
        cout<<(n/10)<<'\n';
    }else if( n < 50)                                         // 能买多少个3瓶
        cout<<(n/30*3 + 1 + n%30/10)<<'\n';
    } else{                                                  // 能买多少个5瓶
        int num = n/50*2 + n/50*5;
        int res = n%50;                                     // 剩下能买多少
        // 处理res
        if(res < 30){
            cout<<(num + res/10)<<'\n';
        } else{
            cout<<(num + (res/30*3 + 1 + res%30/10))<<'\n';
        }
    }
    return 0;
}*/
/*
*summary:  可以用模拟做，考虑用dp，完全背包，代码如下
*/
#include<iostream>
using namespace std;
int dp[303];                                // 全局变量自动初始化为0
int main()
{
    int n, p[] = {0, 10, 30, 50}, v[] = {0, 1, 4, 7};  // 预处理代价，价值
    cin >> n;
    for(int i = 1; i <= 3; i++)
        for(int j = p[i]; j <= n; j++)
            dp[j] = max(dp[j - p[i]] + v[i], dp[j]);    // 消耗同等代价，看哪一种得到的价值最大，打到的酱油越多(#^.^#)
    cout << dp[n] << endl;
    return 0;
}
/*
summary: 满完全背包，后面的决策不会影响前面的决策，故顺序滚动数组
*/
