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
    while(--n){     // ������ߴ�������
        l=t;
        cin>>t;
        maxWav=max(abs(t-l),maxWav);    // �����꼴��������󲨶�
    }
    cout<<maxWav<<'\n';
    return 0;
}
/*
*summary:   ģ��
*/
