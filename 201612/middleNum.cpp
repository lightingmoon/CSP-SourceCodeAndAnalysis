/*
*positon: http://118.190.20.162/view.page?gpid=T52
*/
#include<bits/stdc++.h>
#define LARGE_IO
using namespace std;
int a[1003];
int main()
{
#ifdef LARGE_IO
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif // LARGE_IO
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int l = 0, r = 0, m = (n >> 1);
    for(int i = 0; i < m; i++) {        // ģ���������λ�����ߵ����Ƿ���ȡ�
        if(a[i] < a[m])
            l++;
        if(a[n - i - 1] > a[m])
            r++;
    }
    if(l == r)
        cout << a[m] << '\n';
    else
        cout << "-1" << '\n';
    return 0;
}
/*
*summary:   ���ǵ�ʱ�临�Ӷ� O(N logN)
*/
