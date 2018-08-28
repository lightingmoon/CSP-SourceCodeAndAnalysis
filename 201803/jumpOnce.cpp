/*
*http://118.190.20.162/view.page?gpid=T73
*
*/
// 写注释！
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l , n, score, t = 1;	                   // 连续加分初始为1
    while(true) {
        cin >> n
        if(n == 1) {
            score++;	                          // 加一分
            l = n;	                             // 保存当前情况以与下一个比较
            t = 1;	                            // 连续加分初始化
        } else if(n == 2) {
            if(score == 0 || l == 1) {          // 第一次连续加分
                score += 2;
                t++;
            } else if(l == 2) {
                score += (t++) << 1;	        // 连续加分两次以上累乘2，位运算加速
            }
            l = n;
        } else if( n == 0) {
            break;
        }
    }
    cout << score << "\n";
    return 0;
}
/*
*summary :每输入一次判断一次，增加效率，减少内存占用。
*/
