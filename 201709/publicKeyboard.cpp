/*
*positon:http://118.190.20.162/view.page?gpid=T62
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, k, st = 0x3f3f3f, ct = 0;
    cin >> n >> k;
    int *key = new int[n + 1];                            // Ô¿³×ÐòÁÐ
    for(int i = 1; i <= n; i++)     key[i] = i;
    map<int,vector<int> >  lease;                      // Ô¿³×½è³ö
    map<int, vector<int> > ret;                       // Ô¿³×·Å»Ø
    for(int i = 0 ; i < k; i++) {
        int w, s, c;
        cin >> w >> s >> c;
        ret[s + c].push_back(w);
        lease[s].push_back(w);
        st = min(st, s);
        ct = max(ct, s + c);
    }
    priority_queue<int, vector<int>, greater<int> > rk;
    for(int i = st; i <= ct; i++) {
        if(ret.count(i) != 0) {
            for(size_t j = 0;j<ret[i].size();j++)
                rk.push(ret[i].at(j));
            for(int j = 1;j<=n&&!rk.empty();j++)
                if(key[j] == 0){
                    key[j] = rk.top();
                    rk.pop();
                }
        }
        if(lease.count(i)!=0){
            vector<int>::iterator it = lease[i].begin();
            for(;it != lease[i].end();it++){
                int inx = distance(key,find(key,key+n,*it));
                key[inx] = 0;
            }
            lease.erase(i);
        }
    }
    for(int i = 1 ; i <= n; i++)
        cout << key[i] << (i == n ? "\n" : " ");
    delete[] key;
    return 0;
}
/*
*summary:
*/
