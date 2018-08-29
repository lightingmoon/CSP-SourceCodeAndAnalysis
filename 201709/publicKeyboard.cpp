/*
*positon:http://118.190.20.162/view.page?gpid=T62
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, k, st = 1e9, ct = 0;
    cin >> n >> k;
    int *key = new int[n + 1];                            // 钥匙序列
    for(int i = 1; i <= n; i++)     						// 初始化序列
		key[i] = i;
    map<int,vector<int> >  lease;                      // 钥匙借出
    map<int, vector<int> > ret;                       // 钥匙放回
    for(int i = 0 ; i < k; i++) {
        int w, s, c;
        cin >> w >> s >> c;
        ret[s + c].push_back(w);
        lease[s].push_back(w);
        st = min(st, s);                            // 更新起始时间
        ct = max(ct, s + c);                        // 更新结束时间
    }
    priority_queue<int, vector<int>, greater<int> > rk;		// 优先队列，根据加入的钥匙的编号大小排序
    for(int i = st; i <= ct; i++) {
        // 在相同时间，先还钥匙
        if(ret.count(i) != 0) {
            for(size_t j = 0;j<ret[i].size();j++)           // 该时间在换钥匙时间区间内，将钥匙加入队列
                rk.push(ret[i].at(j));
            for(int j = 1;j<=n&&!rk.empty();j++)            //开始还钥匙
                if(key[j] == 0){                            // 位置为空
                    key[j] = rk.top();
                    rk.pop();
                }
        }
        //  再借钥匙
        if(lease.count(i)!=0){
            vector<int>::iterator it = lease[i].begin();
            for(;it != lease[i].end();it++){
                int inx = distance(key,find(key,key+n,*it));
                key[inx] = 0;                               // 表示该位置钥匙被借走。
            }
            lease.erase(i);                                 // 借完之后将之删除，表示该时间借钥匙完成
        }
    }
    for(int i = 1 ; i <= n; i++)
        cout << key[i] << (i == n ? "\n" : " ");
    delete[] key;
    return 0;
}
/*
*summary: 对 程序 = 算法 + 数据结构 有了一个初步了解，深刻领悟到了它的魅力。
*/
