/*
*positon:
*/
#include<bits/stdc++.h>
#define LARGE_IO
using namespace std;
const int maxSeat = 100;
bitset < maxSeat + 1 > bs;
int main()
{
#ifdef LARGE_IO
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif // LARGE_IO
    vector<int> p;
    int n, s;
    cin >> n;
    while(n--) {
        cin >> s;
        size_t i = 1;
        while(i <= maxSeat) {
            if(!bs[i]) {   // 找连续座位
                p.push_back(i);
                if(p.size() == s) break;
                if(i % 5 == 0) {
                    p.clear();
                }
                i++;
            } else {
                i++;
            }
        }
        if( i == maxSeat + 1 ) { // 表示没有从break跳出，即没找到连续座位，按空分配
            p.clear();
            for(size_t j = 1; j <= maxSeat; j++) {
                if(!bs[j]) {
                    p.push_back(j);
                    if(s == p.size()) break;
                }
            }
        }
        for(size_t j = 0; j < p.size(); j++) {
            bs.set(p[j]);               // 置占位
            cout << p[j] << (j == p.size() - 1 ? '\n' : ' '); // 输出座位

        }
        p.clear();
    }
    return 0;
}
/*
*summary:
*/
