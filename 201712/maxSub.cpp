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
		cin >> p[i];			// 读入数据
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
*summary:考虑到数据量较小，直接暴力求解时间复杂度为 O(N^2)
*		考虑排序,时间复杂度降低为O(N log N)
*/
