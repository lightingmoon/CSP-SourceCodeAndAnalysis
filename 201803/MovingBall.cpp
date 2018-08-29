/*
*resource:http://118.190.20.162/view.page?gpid=T72
*/
#include<bits/stdc++.h>
using namespace std;
int pos[101];					// 保存小球位置
int dr[101];					// 保存小球移动方向
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,L,t;
	cin>>n>>L>>t;
	for(int i=0;i<n;i++){
		cin>>pos[i]; 			// 第i个小球的位置
		dr[i] = 1; 				// 表示初始方向为右
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
	for(int i = 0;i<n;i++)
		cout<<pos[i]<<(i == n-1?"\n":" ");
	return 0;
}
/*
*考虑到图的遍历，上下左右，通过加减1，-1，等数字组合完成遍历，由此启发，利用两个数组,一个保存位置，一个保存运动方向，因为每一秒移动一格，规定方向为右为正方向，其状态数组保存的方向为1，则向左为负方向，状态数组方向为-1，每一秒将原来的位置数组加上状态数组，加完再判定边界以及碰撞。很妙的模拟题，考的知识点挺多的。如物理矢量规定正方向，模拟细节处理，但是想到这种操作却还是有点难度。
*/

