/*
*positon:http://118.190.20.162/view.page?gpid=T67
*/
#include<bits/stdc++.h>
using namespace std;
bool a[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    // ��������
    cin >> n >> k;
    memset(a, false, sizeof(a));    // ģ�����
    int l = 1, m = 1, j;            // ����n-1����Ϸ,��n - 1 ���Ӻ�ֱ������ѭ��
    for(int i = 1; i < n; i++) {    // ����ÿһ����Ϸ��ʼ��������
        j = m;
        while(true) {
            if(j > n) j = 1;
            if( !a[j] && (l % k == 0 || (l % 10) == k) )
                break;
            if(!a[j]) {
                l++;
            }
            j++;
        }
        l++;
        a[j++] = true;              // �ó��б��
        if(i == n - 1) break;       // ֱ������
        if(j > n)   j = 1;
        while(a[j]) {               // ����һ����ʼ������
            j++;
            if(j > n)
                j = 1;
        }
        m = j;
    }
    for(int i = 1; i <= n; i++)     // ���Ӯ��
        if(!a[i]) cout << i << "\n";
    return 0;
}
/*
*   ��ģ�⣬ֻ��Ҫע��ȷ��������ʱ��Ҫ�������������˳��
*/
