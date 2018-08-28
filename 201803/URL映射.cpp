/*
*resource:http://118.190.20.162/view.page?gpid=T71
*
*/
#include<bits/stdc++.h>
using namespace std;
string out="";
bool judge(string &t, string &p)
{

    int l1 = 0, l2 = 0, r1 = p.length(), r2 = t.length();
    while(l1 < r1 && l2 < r2) {
        if(p[l1] == t[l2]) {
            l1++,l2++;
            continue;
        }                   // ÅÐ¶ÏÄÚÈÝ
        if(p[l1++] != '<')  return false;
        out.push_back(' ');
        if(p[l1] == 'i') {
            bool flag=false;
            while(t[l2] && t[l2] >= '0' && t[l2] <= '9') {
                if(t[l2]>'0') flag=true;
                if(flag) out.push_back(t[l2]);
                l2++;
            }
            if(!flag) return false;
            l1 += 4;
        }
        if(p[l1] == 's') {
            string str = "";
            while(t[l2] && t[l2] != '/'){
                str.push_back(t[l2]);
                l2++;
            }
            if(str.length() == 0) return false;
            out.append(str.begin(),str.end());
            l1 += 4;
        }
        if(p[l1] == 'p') {
            while(l2<t.size())
                out.push_back(t[l2++]);
            return true;
        }
    }
    return (l1 == r1) && (l2 == r2);
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    pair<string, string> r[n];
    string t;
    for(int i = 0; i < n; i++)
        cin >> r[i].first >> r[i].second;
    for(int i = 0; i < m; i++) {
        string t;
        bool flag = false;
        cin >> t;
        int j;
        for(j = 0; j < n; j++) {
            if(judge(t, r[j].first)) {
                flag = true;
                break;
            } else{
                out.clear();
            }
        }
        if(flag)   cout << r[j].second << out;
        else       cout << "404";
        cout<<'\n';
        out.clear();
    }
    return 0;
}
/*
*summary:
*
*/






