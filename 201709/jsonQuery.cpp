/*
*positon:http://118.190.20.162/view.page?gpid=T61
*/
#include<bits/stdc++.h>
using namespace std;

map<string, string> prt;

void parseString(string &p)
{
    for(size_t i=0;i<p.size();i++)
        if(p[i]=='\\') p.erase(p.begin()+i);
}
void parse(string &s, string c)
{
    string k, v;
    for(size_t i = 0; i < s.size(); i++) {
        if(s[i] == '"') {
            int j = s.find(':', i + 1);
            k = s.substr(i + 1, j - i - 2);
            if(c != "") k = c + "." + k;
            if(s[j + 1] == '"') {
                if(s.find(",", j + 1) != string::npos) {
                    i = s.find(",", j + 1);
                } else {
                    i = s.size() - 1;
                }
                v = s.substr(j + 2, i - j - 3);
                parseString(k);
                parseString(v);
            } else {
                int cnt = 1;
                i = j + 2;
                while(cnt != 0) {
                    if(s[i] == '{') cnt++;
                    else if(s[i] == '}') cnt--;
                    i++;
                }
                v = s.substr(j + 1, i - j - 1); //将{放进去识别对象
                parse(v, k);
            }
            prt[k] = v;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string js, query;
    string::iterator it;
    cin >> n >> m;  		// 读入行数和询问次数
    cin.ignore(1, '\n');
    while(n--) {
        string in;
        getline(cin, in);
        for(it = in.begin(); it != in.end();)
            if(isspace(*it)) in.erase(it);
            else it++;
        js += in;
    }
    parse(js, "");
    while(m--) {
        cin >> query;
        if(!prt.count(query)) cout << "NOTEXIST" << '\n';
        else {
            if(prt[query][0] == '{') cout << "OBJECT" << '\n';
            else cout << "STRING " << prt[query] << '\n';
        }
    }
    return 0;
}
/*
*summary:全部读入，并处理成一个字符串,从逗号划分传值
*/

