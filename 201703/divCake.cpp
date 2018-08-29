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
		    if(n == 0) { // 此时为最后一个蛋糕，如果重量不够，则只能分给下一个小盆友，即数量加一，循环结束
				cnt++;
				break;
		  	}
		  	last += w; // 累加起来直到重量超过k.

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
*summary: 简单模拟，边输入边处理数据即可。
*/

