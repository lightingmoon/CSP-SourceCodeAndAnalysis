#include<bits/stdc++.h>
using namespace std;
int pos[101];		// 保存小球位置
int dr[101];		// 保存小球移动方向
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,L,t;
	cin>>n>>L>>t;
	for(int i=0;i<n;i++){
		cin>>pos[i]; // 第i个小球的位置
		dr[i] = 1; // 表示初始方向为右
	}
	for(int i =1;i<=t;i++){
		for(int j = 0;j<n;j++) pos[j]+=dr[j];				// 移动小球
		for(int j = 0;j<n;j++){ 							// 计算小球下一秒方向
			if((pos[j] == 0 && dr[j] == -1)||(pos[j] == L && dr[j] == 1))
				dr[j]*=-1; 									// 检查边界
			for(int k = j+1;k < n;k++){						// 检查碰撞
				if(pos[k] == pos[j]){
					dr[k]*=-1;
					dr[j]*=-1;
				}
			}
		}
	}
	cout<<pos[0];
	for(int i = 1;i<n;i++)
		cout<<" "<<pos[i];
	return 0;
}

