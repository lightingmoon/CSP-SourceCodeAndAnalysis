#include<bits/stdc++.h>
using namespace std;
int pos[101];		// ����С��λ��
int dr[101];		// ����С���ƶ�����
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,L,t;
	cin>>n>>L>>t;
	for(int i=0;i<n;i++){
		cin>>pos[i]; // ��i��С���λ��
		dr[i] = 1; // ��ʾ��ʼ����Ϊ��
	}
	for(int i =1;i<=t;i++){
		for(int j = 0;j<n;j++) pos[j]+=dr[j];				// �ƶ�С��
		for(int j = 0;j<n;j++){ 							// ����С����һ�뷽��
			if((pos[j] == 0 && dr[j] == -1)||(pos[j] == L && dr[j] == 1))
				dr[j]*=-1; 									// ���߽�
			for(int k = j+1;k < n;k++){						// �����ײ
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

