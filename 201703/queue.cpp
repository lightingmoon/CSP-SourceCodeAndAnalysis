/*
*positon:http://118.190.20.162/view.page?gpid=T56
*/
#include<bits/stdc++.h>
using namespace std;
list<int> p;
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m,pos,move;
	cin>>n>>m;
	// init
	for(size_t i =1;i<=n;i++)
		p.push_back(i);
	for(int i =0;i<m;i++){
		cin>>pos>>move;
		list<int>::iterator it = find(p.begin(),p.end(),pos);
		it = p.erase(it);
		if(move>0) for(int i=0;i<move;i++) it++;
		else for(int i=0;i<(-move);i++) it--;
		p.insert(it,pos);
	}
	list<int>::iterator it = p.begin();
	cout<<*it++;
	for(;it!=p.end()&&n--;it++)
		cout<<' '<<*it;
    return 0;
}
/*
*summary:
*/

