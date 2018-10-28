#include<bits/stdc++.h>
using namespace std;

typedef struct Node{     // ������Ϣʱ������
    int start;
    int end;
}rest;

queue<rest> H,W;    // �ֱ���СH��С����Ϣʱ���߶���
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
    while(!H.empty() && !W.empty())     // ģ��
    {
        h = H.front();
        w = W.front();
        if(h.start <= w.start)          // СH�Ŀ�ʼ��Ϣʱ��С��СW�Ŀ�ʼ��Ϣʱ��
        {
            if(h.end <= w.start)        // СH�Ľ�����Ϣʱ��С��СW�Ŀ�ʼ��Ϣʱ��
            {
                H.pop();
            }
            else
            {
                if(h.end <= w.end)      // СH�Ľ�����Ϣʱ��С��СW�Ľ�����Ϣʱ��
                {
                    totalTime+=(h.end-w.start);     // �ۼ�ʱ��
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
