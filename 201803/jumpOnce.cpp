
/*
*http://118.190.20.162/view.page?gpid=T73
*/
// дע�ͣ�
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l , n, score, t = 1;	        // �����ӷֳ�ʼΪ1
    while(cin >> n &&n) {
        if(n == 1) {
            score++;	                // ��һ��
            l = n;	                    // ���浱ǰ���������һ���Ƚ�
            t = 1;	                    // �����ӷֽ���
        } else if(n == 2) {
            if(score == 0 || l == 1) { // ��һ�������ӷֻ���һ��
                score += 2;
                t++;
            } else if(l == 2) {
                score += (t++) << 1;	// �����ӷ����������۳�2
            }
            l = n;
        }
 }
    cout << score << "\n";
    return 0;
}
/*
*summary :ÿ����һ���ж�һ�Σ�����Ч�ʣ������ڴ�ռ�á�
*/
