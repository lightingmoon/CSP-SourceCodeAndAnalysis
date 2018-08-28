/*
*positon:http://118.190.20.162/view.page?gpid=T63
*/
#include<bits/stdc++.h>
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
}
/*
*summary:   很水的题，我还粗心了，罚多做一道
*/
