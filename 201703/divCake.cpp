/*
*positon:http://118.190.20.162/view.page?gpid=T57
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
 	int n,k,cnt=0,w,last=0;
 	cin>>n>>k;
  	while(n--){
  		cin>>w;
  		if(last+w<k) {
		    if(n == 0) { // ��ʱΪ���һ�����⣬�����������������һֱ�ӽ���
				cnt++;
				break;
		  	}
		  	last += w; // �ۼ�����ֱ����������w.

 	    }
  		else {
  			last = 0;
  			cnt++;
  		}
    }
    cout<<cnt<<endl;
    return 0;
}
/*
*summary:
*/

