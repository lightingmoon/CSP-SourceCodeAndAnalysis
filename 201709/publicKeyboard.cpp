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
    int *key = new int[n + 1];                            // Կ������
    for(int i = 1; i <= n; i++)     						// ��ʼ������
		key[i] = i;
    map<int,vector<int> >  lease;                      // Կ�׽��
    map<int, vector<int> > ret;                       // Կ�׷Ż�
    for(int i = 0 ; i < k; i++) {
        int w, s, c;
        cin >> w >> s >> c;
        ret[s + c].push_back(w);
        lease[s].push_back(w);
        st = min(st, s);                            // ������ʼʱ��
        ct = max(ct, s + c);                        // ���½���ʱ��
    }
    priority_queue<int, vector<int>, greater<int> > rk;		// ���ȶ��У����ݼ����Կ�׵ı�Ŵ�С����
    for(int i = st; i <= ct; i++) {
        // ����ͬʱ�䣬�Ȼ�Կ��
        if(ret.count(i) != 0) {
            for(size_t j = 0;j<ret[i].size();j++)           // ��ʱ���ڻ�Կ��ʱ�������ڣ���Կ�׼������
                rk.push(ret[i].at(j));
            for(int j = 1;j<=n&&!rk.empty();j++)            //��ʼ��Կ��
                if(key[j] == 0){                            // λ��Ϊ��
                    key[j] = rk.top();
                    rk.pop();
                }
        }
        //  �ٽ�Կ��
        if(lease.count(i)!=0){
            vector<int>::iterator it = lease[i].begin();
            for(;it != lease[i].end();it++){
                int inx = distance(key,find(key,key+n,*it));
                key[inx] = 0;                               // ��ʾ��λ��Կ�ױ����ߡ�
            }
            lease.erase(i);                                 // ����֮��֮ɾ������ʾ��ʱ���Կ�����
        }
    }
    for(int i = 1 ; i <= n; i++)
        cout << key[i] << (i == n ? "\n" : " ");
    delete[] key;
    return 0;
}
/*
*summary: �� ���� = �㷨 + ���ݽṹ ����һ�������˽⣬�������������������
*/
