#include<bits/stdc++.h>
using namespace std;

typedef struct Node{     // 保存休息时间类型
    int start;
    int end;
}rest;

queue<rest> H,W;    // 分别是小H，小的休息时间线队列
int main()
{
    int n;
    rest t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t.start>>t.end;
        H.push(t);
    }
    for(int i=0;i<n;i++)
    {
        cin>>t.start>>t.end;
        W.push(t);
    }
    rest h,w;
    int totalTime=0;
    while(!H.empty() && !W.empty())     // 模拟
    {
        h = H.front();
        w = W.front();
        if(h.start <= w.start)          // 小H的开始休息时间小于小W的开始休息时间
        {
            if(h.end <= w.start)        // 小H的结束休息时间小于小W的开始休息时间
            {
                H.pop();
            }
            else
            {
                if(h.end <= w.end)      // 小H的结束休息时间小于小W的结束休息时间
                {
                    totalTime+=(h.end-w.start);     // 累加时间
                    H.pop();
                }
                else
                {
                    totalTime+=(w.end-w.start);
                    W.pop();
                }
            }
        }
        else
        {
            if(w.end <= h.start)
            {
                W.pop();
            }
            else
            {
                if(h.end <= w.end)
                {
                    totalTime += (h.end - h.start);
                    H.pop();
                }
                else
                {
                    totalTime += (w.end - h.start);
                    W.pop();
                }
            }
        }
    }
    cout<<totalTime<<endl;
	return 0;
}
