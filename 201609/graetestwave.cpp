/*
*positon:  http://118.190.20.162/view.page?gpid=T47
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef LARGE_IO
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif // LARGE_IO
    int n,maxWav=-1,t,l;
    cin>>n;
    cin>>t;
    while(--n){     // 边输入边处理数据
        l=t;
        cin>>t;
        maxWav=max(abs(t-l),maxWav);    // 输入完即更新完最大波动
    }
    cout<<maxWav<<'\n';
    return 0;
}
/*
*summary:   模拟
*/
