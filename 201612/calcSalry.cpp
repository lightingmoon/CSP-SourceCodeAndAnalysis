/*
*positon:http://118.190.20.162/view.page?gpid=T51
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, ac = 0;
    int tax[] = {45, 300, 900, 6500, 6000, 8750};   // 预处理，在这个段位的工资最大的税
    cin >> t;
    if(t <= 3500) cout << t << '\n';
    else if(t <= 4955) cout << (t - 0.03 * 3500) / (1 - 0.03) << '\n';
    else if(t <= 7655) {
        for(int i = 0; i < 1; i++) ac += tax[i];
        cout << (t + ac - (0.1 * 5000)) / (1 - 0.1) << '\n';
    } else if(t <= 11255) {
        for(int i = 0; i < 2; i++) ac += tax[i];
        cout << (t + ac - 0.2 * 8000) / (1 - 0.2) << '\n';
    } else if(t <= 30755) {
        for(int i = 0; i < 3; i++) ac += tax[i];
        cout << (t + ac - 0.25 * 12500) / (1 - 0.25)<< '\n';
    } else if(t <= 44755) {
        for(int i = 0; i < 4; i++) ac += tax[i];
        cout << (t + ac - 0.3 * 38500) / (1 - 0.3) << '\n';
    } else if(t <= 61005) {
        for(int i = 0; i < 5; i++) ac += tax[i];
        cout << (t + ac - 0.35 * 58500  ) / (1 - 0.35) << '\n';
    } else {
        for(int i = 0; i < 6; i++) ac += tax[i];
        cout << (t + ac - 0.45 * 83500 ) / (1 - 0.45) << '\n';
    }
    return 0;
}
/*
*summary: 模拟计算，先推导公式，再计算在相应的工资段位收最大税之后的工资即可。
*/
