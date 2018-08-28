/*
*1ositon:http://118.190.20.162/view.page?gpid=T70
*/
#include<bits/stdc++.h>
using namespace std;
int s[9];
int jud()
{
    // 右下判定
    int sum = 0;
    sum += s[0];
    sum += s[4];
    sum += s[8];
    if(sum == 2) {
        if((s[0] == 1 && s[4] == 1) || (s[4] == 1 && s[8] == 1))
            return 2;
    } else if(sum == 3) {
        if(!(s[0] == 2 || s[4] == 2 || s[8] == 2))
            return 1;
    } else if(sum == 6) return -1;
    // 左上判定
    sum = 0;
    sum += s[2];
    sum += s[4];
    sum += s[6];
    if(sum == 2) {
        if((s[2] == 1 && s[4] == 1) || (s[4] == 1 && s[6] == 1))
            return 2;
    } else if(sum == 3) {
        if(!(s[2] == 2 || s[4] == 2 || s[6] == 2))
            return 1;
    } else if(sum == 6) return -1;
    // 纵判定
    for(int i = 0; i < 3; i++) {
        sum = 0;
        sum += s[i];
        sum += s[i + 3];
        sum += s[i + 6];
        if(sum == 2) {
            if((s[i] == 1 && s[i + 3] == 1) || (s[i + 3] == 1 && s[i + 6] == 1))
                return 2;
            else {
                continue;
            }
        } else if(sum == 3) {
            if(!(s[i] == 2 || s[i + 3] == 2 || s[i + 6] == 2))
                return 1;
        } else if(sum == 6) return -1;
    }
    // 横判定
    for(int i = 0; i < 9; i += 3) {
        sum = 0;
        sum += s[i];
        sum += s[i + 1];
        sum += s[i + 2];
        if(sum == 2) {
            if((s[i] == 1 && s[i + 1] == 2) || (s[i + 2] == 1 && s[i + 1] == 1))
                return 2;
            else
                continue;
        } else if(sum == 3) {
            if(!(s[i] == 2 || s[i + 1] == 2 || s[i + 2] == 2))
                return 1;
        } else if(sum == 6) return -1;
    }

    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(s, 0, sizeof(s));
        int zero = 0;
        for(int i = 0; i < 9; i++) {
            cin >> s[i];
            if(s[i] == 0)  zero++;
        }
        int res = jud();
        if(res == 0) cout << "0" << "\n";
        else if(res == 1) cout << (zero + 1) << "\n";
        else if(res == 2)  cout << zero << "\n";
        else cout << "-" << (zero + 1) << "\n";
    }
    return 0;
}
/*
*summary:
*/
