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
    if(n < 30){                                                 // ����Ǯ�ĵ���
        cout<<(n/10)<<'\n';
    }else if( n < 50)                                         // ������ٸ�3ƿ
        cout<<(n/30*3 + 1 + n%30/10)<<'\n';
    } else{                                                  // ������ٸ�5ƿ
        int num = n/50*2 + n/50*5;
        int res = n%50;                                     // ʣ���������
        // ����res
        if(res < 30){
            cout<<(num + res/10)<<'\n';
        } else{
            cout<<(num + (res/30*3 + 1 + res%30/10))<<'\n';
        }
    }
    return 0;
}*/
/*
*summary:  ������ģ������������dp����ȫ��������������
*/
#include<iostream>
using namespace std;
int dp[303];                                // ȫ�ֱ����Զ���ʼ��Ϊ0
int main()
{
    int n, p[] = {0, 10, 30, 50}, v[] = {0, 1, 4, 7};  // Ԥ������ۣ���ֵ
    cin >> n;
    for(int i = 1; i <= 3; i++)
        for(int j = p[i]; j <= n; j++)
            dp[j] = max(dp[j - p[i]] + v[i], dp[j]);    // ����ͬ�ȴ��ۣ�����һ�ֵõ��ļ�ֵ��󣬴򵽵Ľ���Խ��(#^.^#)
    cout << dp[n] << endl;
    return 0;
}
/*
summary: ����ȫ����������ľ��߲���Ӱ��ǰ��ľ��ߣ���˳���������
*/
