/*
*positon:http://118.190.20.162/view.page?gpid=T68
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, minSub = 1e9;
    cin >> n;
    int *p = new int[n];
    for(int i = 0; i < n; i++)
		cin >> p[i];			// ��������
    sort(p,p+n);
//    for(int i = 0; i < n; i++)	//
//        for(int j = i + 1; j < n; j++)
//            minSub = min(abs(p[i] - p[j]), minSub);
    for(size_t i = 1;i<n;i++)
	   minSub = min(abs(p[i] - p[i - 1]),minSub);
    cout << minSub << "\n";
    delete[] p;
    return 0;
}
/*
*summary:���ǵ���������С��ֱ�ӱ������ʱ�临�Ӷ�Ϊ O(N^2)
*		��������,ʱ�临�ӶȽ���ΪO(N log N)
*/
